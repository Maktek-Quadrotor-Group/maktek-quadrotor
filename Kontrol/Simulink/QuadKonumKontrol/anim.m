function x, y  = anim(k)
%SL3D_SFUNTRAJ S-function for Trajectory scope with setpoint editor.
%   This MATLAB code is used as a Simulink S-function block. Block inputs
%   are X-Y coordinates which are used for plotting the trajectory.
%   By clicking the mouse inside the graph X-Y setpoint can be set 
%   which is the block output.

%   Copyright 1998-2012 HUMUSOFT s.r.o. and The MathWorks, Inc.
%   $Revision: 1.1.6.4.4.1 $ $Date: 2012/06/07 18:19:34 $ $Author: batserve $


model_name = bdroot(gcs);     % extract model name
wh = vrworld(get_param([model_name '/VR Sink'], 'WorldFileName'));
nh = vrnode(wh, 'MouseSensor');
sync(nh, 'hitPoint_changed', 'on');
sync(nh, 'isActive', 'on');

% end mdlInitializeSizes

%
%=============================================================================
% mdlUpdate
%=============================================================================
%
function sys = mdlUpdate(t, x, u, flag, ax, Ts, mode)   %#ok unused parameters

% retrieve the setpoint
switch mode
case 1                   % mouse
  if ~isempty(ud)
    set(FigHandle, 'WindowButtonDownFcn', @LocalMouseButtonDownFcn);
    setpoint = [get(ud.Setpoint, 'XData') get(ud.Setpoint, 'YData')];
  else
    setpoint = [];
  end

case 2                    % signal
  if ~isempty(ud)
    set(FigHandle, 'WindowButtonDownFcn', '');
  end
  setpoint = u(3:4).';

case 3                    % VR sensor
  if ~isempty(ud)
    set(FigHandle, 'WindowButtonDownFcn', '');
  end
  model_name = bdroot(gcs);
  wh = vrworld(get_param([model_name '/VR Sink'], 'WorldFileName'));
  nh = vrnode(wh, 'MouseSensor');
  if getfield(nh, 'isOver') && getfield(nh, 'isActive')                       %#ok<GFLD> this is overloaded GETFIELD
    setpoint = getfield(nh, 'hitPoint_changed');     %#ok<GFLD> this is overloaded GETFIELD
    setpoint = setpoint([1 3]);
    % -z VRML axis is Matlab y axis
    setpoint(2) = -setpoint(2);
  else
    setpoint = [];
  end
end

% update the setpoint value
if ~isempty(setpoint)
  set_param([gcs '/Setpoint'], 'Value', mat2str(setpoint));
end

%
%=============================================================================
% LocalMouseButtonDownFcn
% Sends mouse coordinates to block output.
%=============================================================================
%
function LocalMouseButtonDownFcn(this, eventdata)

set(gcbf, 'WindowButtonMotionFcn', @LocalMouseFcn, ...
          'WindowButtonUpFcn',     @LocalMouseButtonUpFcn);
LocalMouseFcn(this, eventdata)

%
%=============================================================================
% LocalMouseButtonUpFcn
% Sends mouse coordinates to block output.
%=============================================================================
%
function LocalMouseButtonUpFcn(this, eventdata)

set(gcbf, 'WindowButtonMotionFcn', '', ...
          'WindowButtonUpFcn',     '');
LocalMouseFcn(this, eventdata)

%
%=============================================================================
% LocalMouseFcn
% Sends mouse coordinates to block output.
%=============================================================================
%
function LocalMouseFcn(this, eventdata) %#ok<INUSD> eventdata unused

ud = get(this, 'UserData');
mouse = get(get(ud.Setpoint, 'Parent'), 'CurrentPoint');
mouse = mouse(1, 1:2);
Xlim = get(ud.XYAxes, 'XLim');
Ylim = get(ud.XYAxes, 'YLim');
if (mouse(1)>=Xlim(1) && mouse(1)<=Xlim(2) && mouse(2)>=Ylim(1) && mouse(2)<=Ylim(2))
  set(ud.Setpoint, 'XData', mouse(1), 'YData', mouse(2));
end
drawnow;

x = mouse(1)
y = mouse(2)

% end LocalMouseFcn