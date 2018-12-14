/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Lang configuration for the series main summary. Each series type has two modes: 1. This series type is the only series type used in the  chart 2. This is a combination chart with multiple series types If a definition does not exist for the specific series type and mode, the 'default' lang definitions are used.
*/
@interface HISummary: HIChartsJSONSerializable

@property(nonatomic, readwrite) NSString *pieCombination;
@property(nonatomic, readwrite) NSString *pie;
@property(nonatomic, readwrite) NSString *lineCombination;
@property(nonatomic, readwrite) NSString *mapbubble;
@property(nonatomic, readwrite) NSString *spline;
@property(nonatomic, readwrite) NSString *barCombination;
@property(nonatomic, readwrite) NSString *boxplotCombination;
@property(nonatomic, readwrite) NSString *splineCombination;
@property(nonatomic, readwrite) NSString *scatterCombination;
@property(nonatomic, readwrite) NSString *maplineCombination;
@property(nonatomic, readwrite) NSString *bubble;
@property(nonatomic, readwrite) NSString *boxplot;
@property(nonatomic, readwrite) NSString *columnCombination;
@property(nonatomic, readwrite) NSString *map;
@property(nonatomic, readwrite) NSString *line;
@property(nonatomic, readwrite) NSString *mapline;
@property(nonatomic, readwrite) NSString *bar;
@property(nonatomic, readwrite) NSString *mapCombination;
@property(nonatomic, readwrite) NSString *defaults;
@property(nonatomic, readwrite) NSString *mapbubbleCombination;
@property(nonatomic, readwrite) NSString *defaultCombination;
@property(nonatomic, readwrite) NSString *column;
@property(nonatomic, readwrite) NSString *bubbleCombination;
@property(nonatomic, readwrite) NSString *scatter;

-(NSDictionary *)getParams;

@end
