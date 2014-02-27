function [sys, x0, str, ts, simStateCompliance] = sl3d_sfuntraj(t, x, u, flag, ax, Ts, mode)
%SL3D_SFUNTRAJ S-function for Trajectory scope with setpoint editor.
%   This MATLAB code is used as a Simulink S-function block. Block inputs
%   are X-Y coordinates which are used for plotting the trajectory.
%   By clicking the mouse inside the graph X-Y setpoint can be set 
%   which is the block output.

%   Copyright 1998-2012 HUMUSOFT s.r.o. and The MathWorks, Inc.
%   $Revision: 1.1.6.4.4.1 $ $Date: 2012/06/07 18:19:34 $ $Author: batserve $


switch flag

  %%%%%%%%%%%%%%%%%%
  % Initialization %
  %%%%%%%%%%%%%%%%%%
  case 0
    [sys, x0, str, ts, simStateCompliance] = mdlInitializeSizes(ax, Ts);

  %%%%%%%%%%
  % Update %
  %%%%%%%%%%
  case 2

  %%%%%%%%%
  % Start %
  %%%%%%%%%
  case 'Start'
    LocalBlockStartFcn

  %%%%%%%%
  % Stop %
  %%%%%%%%
  case 'Stop'
    LocalBlockStopFcn

  %%%%%%%%%%%%%%
  % NameChange %
  %%%%%%%%%%%%%%
  case 'NameChange'
    LocalBlockNameChangeFcn

  %%%%%%%%%%%%%%%%%%%%%%%%
  % CopyBlock, LoadBlock %
  %%%%%%%%%%%%%%%%%%%%%%%%
  case { 'CopyBlock', 'LoadBlock' }
    LocalBlockLoadCopyFcn

  %%%%%%%%%%%%%%%
  % DeleteBlock %
  %%%%%%%%%%%%%%%
  case 'DeleteBlock'
    LocalBlockDeleteFcn

  % Unused flags %
  case { 1, 3, 9 }
    sys = [];

  % Other flags
  otherwise
    if ischar(flag),
      DAStudio.error('Simulink:blocks:unhandledFlag', flag);
    else
      DAStudio.error('Simulink:blocks:unhandledFlag', num2str(flag));
    end

end

% end sl3d_sfuntraj


%
%=============================================================================
% mdlInitializeSizes
% Return the sizes, initial conditions, and sample times for the S-function.
%=============================================================================
%
function [sys, x0, str, ts, simStateCompliance] = mdlInitializeSizes(ax, Ts)

if length(ax)~=4
  DAStudio.error('Simulink:blocks:axisLimitsMustBeDefined');
end

if ~strcmpi(vrgetpref('DataTypeBool'), 'logical')
  error(message('sl3d:demos:incompatibledatatypepref'));
end

sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 0;
sizes.NumInputs      = 4;
sizes.DirFeedthrough = 0;
sizes.NumSampleTimes = 1;
sys = simsizes(sizes);

x0 = [];

str = [];

if ~isempty(Ts)
  ts = [Ts(1) 0];
else
  ts = [-1 0];
end

% setpointecify that the simState for this s-function is same as the default
simStateCompliance = 'DefaultSimState';

model_name = bdroot(gcs);     % extract model name
wh = vrworld(get_param([model_name '/Animasyon/VRSink'], 'WorldFileName'));
nh = vrnode(wh, 'MouseSensor');
sync(nh, 'hitPoint_changed', 'on');
sync(nh, 'isActive', 'on');

% end mdlInitializeSizes

%
%=============================================================================
% mdlUpdate
%=============================================================================
%
% end mdlUpdate

%
%=============================================================================
% LocalBlockStartFcn
% Function that is called when the simulation starts.  Initialize the
% Trajectory Graph scope figure.
%=============================================================================
%
function LocalBlockStartFcn

% get the figure associated with this block, create a figure if it doesn't
% exist
FigHandle = GetSfuntrajFigure(gcbh);
if ~ishandle(FigHandle)
  FigHandle = CreateSfuntrajFigure;
end
ud = get(FigHandle, 'UserData');

% clear the previous line
ud.XYData = zeros(0, 2);
if isa(ud.XYLine, 'hg2sample.LineAnimator') 
  clearVertices(ud.XYLine);
elseif isnumeric(ud.XYLine)
  set(ud.XYLine, 'EraseMode', 'normal', 'XData', [], 'YData', []);
  set(ud.XYLine, 'EraseMode', 'none');
end

% initialize setpoint
xl = get(ud.XYAxes, 'XLim');
yl = get(ud.XYAxes, 'YLim');
setpoint = [(xl(1)+xl(2)) (yl(1)+yl(2))]./2;
set(ud.Setpoint, 'XData', setpoint(1));
set(ud.Setpoint, 'YData', setpoint(2));
set_param([gcb '/Setpoint'], 'Value', mat2str(setpoint));

set(FigHandle, 'UserData', ud);

% end LocalBlockStartFcn

%
%=============================================================================
% LocalBlockStopFcn
% At the end of the simulation, set the line's X and Y data to contain
% the complete set of points that were acquire during the simulation.
% Recall that during the simulation, the lines are only small segments from
% the last time step to the current one.
%=============================================================================
%
function LocalBlockStopFcn

FigHandle = GetSfuntrajFigure(gcbh);
if ishandle(FigHandle)
  ud = get(FigHandle, 'UserData');
  if ~isa(ud.XYLine, 'hg2sample.LineAnimator')
    set(ud.XYLine, 'XData', ud.XYData(:, 1), 'YData', ud.XYData(:, 2));
  end
end

% end LocalBlockStopFcn

%
%=============================================================================
% LocalBlockNameChangeFcn
% Function that handles name changes on the Graph scope block.
%=============================================================================
%
function LocalBlockNameChangeFcn

% get the figure associated with this block, if it's valid, change
% the name of the figure
FigHandle = GetSfuntrajFigure(gcbh);
if ishandle(FigHandle)
  set(FigHandle, 'Name', get_param(gcbh, 'Name'));
end

% end LocalBlockNameChangeFcn

%
%=============================================================================
% LocalBlockLoadCopyFcn
% This is the XYGraph block's LoadFcn and CopyFcn.  Initialize the block's
% UserData such that a figure is not associated with the block.
%=============================================================================
%
function LocalBlockLoadCopyFcn

SetSfuntrajFigure(gcbh, -1);

% end LocalBlockLoadCopyFcn

%
%=============================================================================
% LocalBlockDeleteFcn
% This is the XY Graph block'DeleteFcn.  Delete the block's figure window,
% if present, upon deletion of the block.
%=============================================================================
%
function LocalBlockDeleteFcn

% Get the figure handle associated with the block, if it exists, delete
% the figure.
FigHandle = GetSfuntrajFigure(gcbh);
if ishandle(FigHandle)
  delete(FigHandle);
  SetSfuntrajFigure(gcbh, -1);
end

% end LocalBlockDeleteFcn

%
%=============================================================================
% LocalFigureDeleteFcn
% This is the XY Graph figure window's DeleteFcn.  The figure window is
% being deleted, update the XY Graph block's UserData to reflect the change.
%=============================================================================
%
function LocalFigureDeleteFcn(this, eventdata) %#ok<INUSD> eventdata unused

% Get the block associated with this figure and set its figure to -1
ud = get(this, 'UserData');
SetSfuntrajFigure(ud.Block, -1);

% end LocalFigureDeleteFcn

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

% end LocalMouseFcn

%
%=============================================================================
% GetSfuntrajFigure
% Retrieves the figure window associated with this S-function XY Graph block
% from the block's parent subsystem's UserData.
%=============================================================================
%
function FigHandle = GetSfuntrajFigure(block)

if strcmp(get_param(block, 'BlockType'), 'S-Function'),
  block = get_param(block, 'Parent');
end

FigHandle = get_param(block, 'UserData');
if isempty(FigHandle),
  FigHandle=-1;
end

% end GetSfuntrajFigure

%
%=============================================================================
% SetSfuntrajFigure
% Stores the figure window associated with this S-function XY Graph block
% in the block's parent subsystem's UserData.
%=============================================================================
%
function SetSfuntrajFigure(block, FigHandle)

if strcmp(get_param(bdroot, 'BlockDiagramType'), 'model'),
  if strcmp(get_param(block, 'BlockType'), 'S-Function'),
    block = get_param(block, 'Parent');
  end

  set_param(block, 'UserData', FigHandle);
end

% end SetSfuntrajFigure

%
%=============================================================================
% CreateSfuntrajFigure
% Creates the figure window associated with this S-function XY Graph block.
%=============================================================================
%
function FigHandle = CreateSfuntrajFigure

% the figure doesn't exist, create one
screenLoc = get(0, 'ScreenSize');
origin = max(-screenLoc(1:2), 0) + 100;
FigHandle = figure('Units',          'pixels', ...
                   'Position',       [origin 400 300], ...
                   'Name',           get_param(gcbh, 'Name'), ...
                   'Tag',            'TRAJSCOPE', ...
                   'NumberTitle',    'off', ...
                   'IntegerHandle',  'off', ...
                   'ToolBar',        'none', ...
                   'MenuBar',        'none', ...
                   'DeleteFcn',      @LocalFigureDeleteFcn);

% store the block's handle in the figure's UserData
ud.Block = gcbh;

% create various objects in the figure
ud.XYAxes = axes;

% create the markers
ud.XYLineHead = line(0, 0, 'Marker', 'o', 'MarkerEdgeColor', 'r');
ud.Setpoint = line(0, 0, 'Marker', 'o', 'MarkerEdgeColor', 'g');

% create the animated line
try
  % try the HG2 line animator first
  ud.XYLine = hg2sample.LineAnimator('Parent', ud.XYAxes);
  set(ud.XYLine, 'MaxNumberOfSegments', 1000);

catch ME %#ok<NASGU>
  % use plain line if the above failed
  ud.XYLine = line(0, 0, 'LineStyle', '-', 'Color', 'b');
  
  % we can use EraseMode on HG1
  if isnumeric(ud.XYAxes)
    set(ud.XYLine, 'EraseMode', 'none');
    set(ud.XYLineHead, 'EraseMode', 'xor');
    set(ud.Setpoint, 'EraseMode', 'xor');
  end
end

title('Trajectory Graph');
xlabel('X Axis');
ylabel('Y Axis');
ud.XYData   = zeros(0,2);

% Associate the figure with the block, and set the figure's UserData.
SetSfuntrajFigure(gcbh, FigHandle);
set(FigHandle, 'HandleVisibility', 'callback', 'UserData', ud);

% end CreateSfuntrajFigure
