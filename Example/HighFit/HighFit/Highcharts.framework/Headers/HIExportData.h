/**
* (c) 2009-2020 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
The text for exported table.
*/
@interface HIExportData: HIChartsJSONSerializable

/**
The annotation column title.
*/
@property(nonatomic, readwrite) NSString *annotationHeader;
/**
The category column title.
*/
@property(nonatomic, readwrite) NSString *categoryHeader;
/**
The category column title when axis type set to "datetime".
*/
@property(nonatomic, readwrite) NSString *categoryDatetimeHeader;

-(NSDictionary *)getParams;

@end
