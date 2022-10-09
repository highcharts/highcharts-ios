/**
* (c) 2009-2021 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options for the connector in the _Series on point_ feature. In styled mode, the connector can be styled with the `.highcharts-connector-seriesonpoint` class name.
*/
@interface HIConnectorOptions: HIChartsJSONSerializable

/**
Pixel width of the connector line.

**Defaults to** `1`.
*/
@property(nonatomic, readwrite) NSNumber *width;
/**
A name for the dash style to use for the connector.
*/
@property(nonatomic, readwrite) NSString *dashstyle;
/**
Color of the connector line. By default it's the series' color.
*/
@property(nonatomic, readwrite) NSString *stroke;

-(NSDictionary *)getParams;

@end
