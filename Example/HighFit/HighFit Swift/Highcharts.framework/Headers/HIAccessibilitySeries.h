/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISummary.h"


/**
Lang configuration for different series types. For more dynamic control over the series element descriptions, see `accessibility.seriesDescriptionFormatter`.
*/
@interface HIAccessibilitySeries: HIChartsJSONSerializable

/**
User supplied description text. This is added after the main summary if present.

**Defaults to** `{description}`.
*/
@property(nonatomic, readwrite) NSString *definition;
/**
Lang configuration for the series main summary. Each series type has two modes:

	1. This series type is the only series type used in the chart
	2. This is a combination chart with multiple series types

If a definition does not exist for the specific series type and mode, the 'default' lang definitions are used.
*/
@property(nonatomic, readwrite) HISummary *summary;
/**
xAxis description for series if there are multiple xAxes in the chart.

**Defaults to** `X axis, {name}`.
*/
@property(nonatomic, readwrite) NSString *xAxisDescription;
/**
yAxis description for series if there are multiple yAxes in the chart.

**Defaults to** `Y axis, {name}`.
*/
@property(nonatomic, readwrite) NSString *yAxisDescription;

-(NSDictionary *)getParams;

@end
