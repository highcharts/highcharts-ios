/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIAreasplineMarkerStatesSelect.h"
#import "HIAreasplineMarkerStatesHover.h"


@interface HIAreasplineMarkerStates: HIChartsJSONSerializable

/**
* description: The appearance of the point marker when selected. In order to allow a point to be 
		selected, set the series.allowPointSelect option to true.
*/
@property(nonatomic, readwrite) HIAreasplineMarkerStatesSelect *select;
@property(nonatomic, readwrite) HIAreasplineMarkerStatesHover *hover;

-(NSDictionary *)getParams;

@end
