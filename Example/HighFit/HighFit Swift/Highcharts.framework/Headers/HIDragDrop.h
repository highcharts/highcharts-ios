/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIGuideBox.h"
#import "HIDragHandle.h"


/**
The draggable-points module allows points to be moved around or modified in the chart. In addition to the options mentioned under the `dragDrop` API structure, the module fires three events, `point.dragStart`, `point.drag` and `point.drop`.

**Try it**

* [Draggable column and line series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/resize-column)
* [Draggable bar](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/bar-series)
* [Draggable bubbles](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/drag-bubble)
* [Draggable X range series](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/drag-xrange)
*/
@interface HIDragDrop: HIChartsJSONSerializable

/**
Allow high value to be dragged individually.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *draggableHigh;
/**
Allow low value to be dragged individually.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *draggableLow;
/**
Allow x2 value to be dragged individually.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *draggableX2;
/**
Allow x value to be dragged individually.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *draggableX1;
/**
Allow Q1 value to be dragged individually.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *draggableQ1;
/**
Allow Q3 value to be dragged individually.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *draggableQ3;
/**
Allow target value to be dragged individually.

**Defaults to** `true`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *draggableTarget;
/**
Style options for the guide box. The guide box has one state by default, the `default` state.
*/
@property(nonatomic, readwrite) HIGuideBox *guideBox;
/**
Set the maximum X value the points can be moved to.

**Try it**

* [Limit dragging](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/drag-xrange)
*/
@property(nonatomic, readwrite) NSNumber *dragMaxX;
/**
Set the maximum Y value the points can be moved to.

**Try it**

* [Limit dragging](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/drag-xrange)
*/
@property(nonatomic, readwrite) NSNumber *dragMaxY;
/**
The X precision value to drag to for this series. Set to 0 to disable. By default this is disabled, except for category axes, where the default is 1.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *dragPrecisionX;
/**
The Y precision value to drag to for this series. Set to 0 to disable. By default this is disabled, except for category axes, where the default is 1.

**Defaults to** `0`.
*/
@property(nonatomic, readwrite) NSNumber *dragPrecisionY;
/**
Set the minimum X value the points can be moved to.

**Try it**

* [Limit dragging](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/drag-xrange)
*/
@property(nonatomic, readwrite) NSNumber *dragMinX;
/**
Set the minimum Y value the points can be moved to.

**Try it**

* [Limit dragging](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/drag-xrange)
*/
@property(nonatomic, readwrite) NSNumber *dragMinY;
/**
Enable dragging in the Y dimension. Note that this is not supported for TreeGrid axes (the default axis type in Gantt charts).
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *draggableY;
/**
Enable dragging in the X dimension.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *draggableX;
/**
The amount of pixels to drag the pointer before it counts as a drag operation. This prevents drag/drop to fire when just clicking or selecting points.

**Defaults to** `2`.
*/
@property(nonatomic, readwrite) NSNumber *dragSensitivity;
/**
Group the points by a property. Points with the same property value will be grouped together when moving.

**Try it**

* [Drag grouped points](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/drag-xrange)
*/
@property(nonatomic, readwrite) NSString *groupBy;
/**
Options for the drag handles.
*/
@property(nonatomic, readwrite) HIDragHandle *dragHandle;
/**
Update points as they are dragged. If false, a guide box is drawn to illustrate the new point size.

**Defaults to** `true`.

**Try it**

* [liveRedraw disabled](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/dragdrop/drag-xrange)
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *liveRedraw;

-(NSDictionary *)getParams;

@end
