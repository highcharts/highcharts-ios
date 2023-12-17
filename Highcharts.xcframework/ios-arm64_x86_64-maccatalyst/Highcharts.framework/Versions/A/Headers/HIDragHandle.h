/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"
#import "HIFunction.h"


/**
Options for the drag handles available in column series.
*/
@interface HIDragHandle: HIChartsJSONSerializable

/**
The class name of the drag handles. Defaults to `highcharts-drag-handle`.

**Defaults to** `highcharts-drag-handle`.
*/
@property(nonatomic, readwrite) NSString *className;
/**
The fill color of the drag handles.

**Defaults to** `#fff`.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
The line width for the drag handles.

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;
/**
The z index for the drag handles.

**Defaults to** `901`.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
The line color of the drag handles.

**Defaults to** `rgba(0, 0, 0, 0.6)`.
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
The mouse cursor to use for the drag handles. By default this is intelligently switching between `ew-resize` and `ns-resize` depending on the direction the point is being dragged.
*/
@property(nonatomic, readwrite) NSString *cursor;
/**
Function to define the SVG path to use for the drag handles. Takes the point as argument. Should return an SVG path in array format. The SVG path is automatically positioned on the point.
*/
@property(nonatomic, readwrite) HIFunction *pathFormatter;

-(NSDictionary *)getParams;

@end
