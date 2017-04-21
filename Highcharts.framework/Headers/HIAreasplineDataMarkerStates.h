/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAreasplineDataMarkerStatesHover.h"
#import "HIAreasplineDataMarkerStatesSelect.h"


@interface HIAreasplineDataMarkerStates: HIChartsJSONSerializable

@property(nonatomic, readwrite) HIAreasplineDataMarkerStatesHover *hover;
/**
* description: The appearance of the point marker when selected. In order to allow a point to be 
		selected, set the series.allowPointSelect option to true.
*/
@property(nonatomic, readwrite) HIAreasplineDataMarkerStatesSelect *select;

-(NSDictionary *)getParams;

@end
