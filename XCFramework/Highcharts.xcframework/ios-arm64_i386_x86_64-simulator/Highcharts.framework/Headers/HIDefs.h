/**
* (c) 2009-2020 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HISVGDefinitionObject.h"


/**
Options for configuring markers for annotations. An example of the arrow marker:  {  arrow: {   id: 'arrow',   tagName: 'marker',   refY: 5,   refX: 5,   markerWidth: 10,   markerHeight: 10,   children: [{    tagName: 'path',    attrs: {     d: 'M 0 0 L 10 5 L 0 10 Z',     strokeWidth: 0    }   }]  } } 

**Try it**

* [Define a custom marker for annotations](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/custom-markers/)
* [Define markers in a styled mode](https://jsfiddle.net/gh/get/library/pure/highcharts/highcharts/tree/master/samples/highcharts/css/annotations-markers/)
*/
@interface HIDefs: HIChartsJSONSerializable

@property(nonatomic, readwrite) HISVGDefinitionObject *reverseArrow;
@property(nonatomic, readwrite) HISVGDefinitionObject *arrow;

-(NSDictionary *)getParams;

@end
