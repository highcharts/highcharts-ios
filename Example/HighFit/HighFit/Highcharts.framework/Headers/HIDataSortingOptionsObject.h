/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Options for `dataSorting`.
*/
@interface HIDataSortingOptionsObject: HIChartsJSONSerializable

/**
Enable or disable data sorting for the series.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *enabled;
/**
Whether to allow matching points by name in an update.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *matchByName;
/**
Determines what data value should be used to sort by.
*/
@property(nonatomic, readwrite) NSString *sortKey;

-(NSDictionary *)getParams;

@end
