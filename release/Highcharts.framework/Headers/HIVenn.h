/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISeries.h"


/**
 A `venn` series. If the `type` option is not specified, it is inherited from `chart.type`.
 
 Configuration options for the series are given in three levels:
 
 1. Options for all series in a chart are defined in the `plotOptions.series` object.
 
 2. Options for all `venn` series are defined in `plotOptions.venn`.
 
 3. Options for one single series are given in `the series instance array`.
 
 <pre>
 Highcharts.chart('container', {
    plotOptions: {
        series: {
            // general options for all series
        },
        venn: {
            // shared options for all venn series
        }
    },
    series: [{
        // specific options for this series instance
        type: 'venn'
    }]
 });
 <pre>
 */
@interface HIVenn: HISeries

@property(nonatomic, readwrite) NSNumber /* Bool */ *colorByPoint;
@property(nonatomic, readwrite) NSNumber *opacity;
@property(nonatomic, readwrite) NSString *borderDashStyle;
@property(nonatomic, readwrite) NSNumber *brighten;

-(NSDictionary *)getParams;

@end
