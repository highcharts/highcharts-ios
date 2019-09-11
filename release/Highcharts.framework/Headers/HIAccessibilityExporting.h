/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Lang configuration for different series types. For more dynamic control over the series element descriptions, see `accessibility.seriesDescriptionFormatter`.
*/
@interface HIAccessibilityExporting: HIChartsJSONSerializable

/**
**Defaults to** `Chart export`.
*/
@property(nonatomic, readwrite) NSString *chartMenuLabel;
/**
**Defaults to** `Chart export menu`.
*/
@property(nonatomic, readwrite) NSString *exportRegionLabel;
/**
**Defaults to** `View export menu`.
*/
@property(nonatomic, readwrite) NSString *menuButtonLabel;

-(NSDictionary *)getParams;

@end
