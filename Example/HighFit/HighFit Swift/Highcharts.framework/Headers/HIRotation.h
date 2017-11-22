/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: Rotation options for the words in the wordcloud.

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/wordcloud-rotation : Word cloud with rotation
*/
@interface HIRotation: HIChartsJSONSerializable

/**
* description: The largest degree of rotation for a word.
* default: 90
*/
@property(nonatomic, readwrite) NSNumber *to;
/**
* description: The number of possible orientations for a word, within the range of
rotation.from and rotation.to.
* default: 2
*/
@property(nonatomic, readwrite) NSNumber *orientations;
/**
* description: The smallest degree of rotation for a word.
*/
@property(nonatomic, readwrite) NSNumber *from;

-(NSDictionary *)getParams;

@end
