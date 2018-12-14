/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"
#import "HIColor.h"


/**
Style options for the guide box default state.
*/
@interface HIDefault: HIChartsJSONSerializable

/**
Guide box zIndex.
*/
@property(nonatomic, readwrite) NSNumber *zIndex;
/**
Guide box fill color.
*/
@property(nonatomic, readwrite) HIColor *color;
/**
CSS class name of the guide box in this state. Defaults to `highcharts-drag-box-default`.
*/
@property(nonatomic, readwrite) NSString *className;
/**
Guide box cursor.
*/
@property(nonatomic, readwrite) NSString *cursor;
/**
Color of the border around the guide box.
*/
@property(nonatomic, readwrite) HIColor *lineColor;
/**
Width of the line around the guide box.
*/
@property(nonatomic, readwrite) NSNumber *lineWidth;

-(NSDictionary *)getParams;

@end
