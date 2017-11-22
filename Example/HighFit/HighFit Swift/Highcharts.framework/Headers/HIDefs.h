/**
* (c) 2009-2017 Highsoft AS
*
* License: www.highcharts.com/license
* For commercial usage, a valid license is required. To purchase a license for Highcharts iOS, please see our website: https://shop.highsoft.com/
* In case of questions, please contact sales@highsoft.com
*/

#import "HIChartsJSONSerializable.h"


/**
* description: Styled mode only. Configuration object for adding SVG definitions for
reusable elements. See http://www.
highcharts.com/docs/chart-design-and-style/gradients-shadows-and-
patterns : gradients, shadows and patterns for more information and code examples.
*/
@interface HIDefs: HIChartsJSONSerializable

/**
* description: Options for configuring markers for annotations.
An example of the arrow marker:

{
  arrow: {
    id: 'arrow',
    refY: 5,
    refX: 5,
    markerWidth: 10,
    markerHeight: 10,
    children: [{
      tagName: 'path',
      attrs: {
        d: 'M 0 0 L 10 5 L 0 10 Z',
        strokeWidth: 0
      }
    }]
  }
}

* demo: https://jsfiddle.net/gh/library/pure/highcharts/highcharts/tree/master/samples/highcharts/annotations/custom-markers/ : Define a custom marker for annotations
*/
@property(nonatomic, readwrite) id markers;

-(NSDictionary *)getParams;

@end
