/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Map data object.
*/
@interface HIMapDataObject: HIChartsJSONSerializable

/**
The name of the data.
*/
@property(nonatomic, readwrite) NSString *name;
/**
The SVG path.
*/
@property(nonatomic, readwrite) NSArray /* <NSNumber, NSString> */ *path;
/**
The GeoJSON meta data.
*/
@property(nonatomic, readwrite) id properties;

-(NSDictionary *)getParams;

@end
