!/**
 * Highstock JS v11.4.7 (2024-08-14)
 *
 * Indicator series type for Highcharts Stock
 *
 * (c) 2010-2024 Paweł Dalek
 *
 * License: www.highcharts.com/license
 */function(t){"object"==typeof module&&module.exports?(t.default=t,module.exports=t):"function"==typeof define&&define.amd?define("highcharts/indicators/natr",["highcharts","highcharts/modules/stock"],function(e){return t(e),t.Highcharts=e,t}):t("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(t){"use strict";var e=t?t._modules:{};function o(e,o,n,r){e.hasOwnProperty(o)||(e[o]=r.apply(null,n),"function"==typeof CustomEvent&&t.win.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:o,module:e[o]}})))}o(e,"Stock/Indicators/NATR/NATRIndicator.js",[e["Core/Series/SeriesRegistry.js"],e["Core/Utilities.js"]],function(t,e){var o,n=this&&this.__extends||(o=function(t,e){return(o=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(t,e){t.__proto__=e}||function(t,e){for(var o in e)Object.prototype.hasOwnProperty.call(e,o)&&(t[o]=e[o])})(t,e)},function(t,e){if("function"!=typeof e&&null!==e)throw TypeError("Class extends value "+String(e)+" is not a constructor or null");function n(){this.constructor=t}o(t,e),t.prototype=null===e?Object.create(e):(n.prototype=e.prototype,new n)}),r=t.seriesTypes.atr,i=e.merge,s=function(t){function e(){return null!==t&&t.apply(this,arguments)||this}return n(e,t),e.prototype.getValues=function(e,o){var n=t.prototype.getValues.apply(this,arguments),r=n.values.length,i=e.yData,s=0,a=o.period-1;if(n){for(;s<r;s++)n.yData[s]=n.values[s][1]/i[a][3]*100,n.values[s][1]=n.yData[s],a++;return n}},e.defaultOptions=i(r.defaultOptions,{tooltip:{valueSuffix:"%"}}),e}(r);return t.registerSeriesType("natr",s),s}),o(e,"masters/indicators/natr.src.js",[e["Core/Globals.js"]],function(t){return t})});