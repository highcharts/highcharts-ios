/**
* (c) 2009-2024 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISummary.h"
#import "HIFunction.h"


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
Description for the value of null points.

**Defaults to** `No value`.
*/
@property(nonatomic, readwrite) NSString *nullPointValue;
/**
Description for annotations on a point, as it is made available to assistive technology.

**Defaults to** `{Annotation: #each(annotations). }`.
*/
@property(nonatomic, readwrite) NSString *pointAnnotationsDescription;
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
/**
Whether or not to add series descriptions to charts with a single series.

**Defaults to** `false`.
*/
@property(nonatomic, readwrite) NSNumber /* Bool */ *describeSingleSeries;
/**
Formatter function to use instead of the default for series descriptions. Receives one argument, `series`, referring to the series to describe. Should return a string with the description of the series for a screen reader user. If `false` is returned, the default formatter will be used for that series.

**Defaults to** `undefined`.
*/
@property(nonatomic, readwrite) HIFunction /* Bool */ *descriptionFormatter;
/**
When a series contains more points than this, we no longer expose information about individual points to screen readers.

**Defaults to** `200`.
*/
@property(nonatomic, readwrite) NSNumber *pointDescriptionEnabledThreshold;

-(NSDictionary *)getParams;

@end
