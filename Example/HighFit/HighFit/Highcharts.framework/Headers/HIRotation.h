/**
* (c) 2009-2018 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
Rotation options for the words in the wordcloud.

**Try it**

* [Word cloud with rotation](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/plotoptions/wordcloud-rotation)
*/
@interface HIRotation: HIChartsJSONSerializable

/**
The largest degree of rotation for a word.
*/
@property(nonatomic, readwrite) NSNumber *to;
/**
The smallest degree of rotation for a word.
*/
@property(nonatomic, readwrite) NSNumber *from;
/**
The number of possible orientations for a word, within the range of `rotation.from` and `rotation.to`. Must be a number larger than 0.
*/
@property(nonatomic, readwrite) NSNumber *orientations;

-(NSDictionary *)getParams;

@end
