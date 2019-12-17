/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Chart and map zoom accessibility language options.
*/
@interface HIZoom: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *mapZoomIn;
@property(nonatomic, readwrite) NSString *resetZoomButton;
@property(nonatomic, readwrite) NSString *mapZoomOut;

-(NSDictionary *)getParams;

@end
