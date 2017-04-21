/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* Any commercial use of Highcharts iOS wrapper (beta version) is prohibited.
* In case of questions, please contact sales@highsoft.com
*/

#import "HIPolygonMarkerStatesSelect.h"
#import "HIPolygonMarkerStatesHover.h"


@interface HIPolygonMarkerStates: HIChartsJSONSerializable

/**
* description: The appearance of the point marker when selected. In order to allow a point to be 
		selected, set the series.allowPointSelect option to true.
*/
@property(nonatomic, readwrite) HIPolygonMarkerStatesSelect *select;
@property(nonatomic, readwrite) HIPolygonMarkerStatesHover *hover;

-(NSDictionary *)getParams;

@end
