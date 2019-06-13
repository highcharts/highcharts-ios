/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIStyle.h"


/**
Options for annotation's control points. Each control point inherits options from controlPointOptions object. Options from the controlPointOptions can be overwritten by options in a specific control point.
*/
@interface HIControlPointOptions: HIChartsJSONSerializable

@property(nonatomic, readwrite) HIStyle *style;
@property(nonatomic, readwrite) NSNumber *width;
@property(nonatomic, readwrite) NSString *symbol;
@property(nonatomic, readwrite) NSNumber *height;
@property(nonatomic, readwrite) NSNumber /* Bool */ *visible;
@property(nonatomic, readwrite) id positioner;

-(NSDictionary *)getParams;

@end
