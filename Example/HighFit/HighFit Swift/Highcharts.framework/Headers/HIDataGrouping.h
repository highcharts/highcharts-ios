/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Data grouping options for the wind barbs. In Highcharts, this requires the `modules/datagrouping.js` module to be loaded. In Highstock, data grouping is included.

**Try it**

* [Wind barb with data grouping](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/windbarb-datagrouping)
*/
@interface HIDataGrouping: HIChartsJSONSerializable

/**
Approximation function for the data grouping. The default returns an average of wind speed and a vector average direction weighted by wind speed.
*/
@property(nonatomic, readwrite) NSString *approximation;
/**
Whether to enable data grouping.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
The approximate data group width.
*/
@property(nonatomic, readwrite) NSNumber *groupPixelWidth;

-(NSDictionary *)getParams;

@end
