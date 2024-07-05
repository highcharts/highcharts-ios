!/**
 * Highstock JS v11.4.5 (2024-07-04)
 *
 * Indicator series type for Highcharts Stock
 *
 * (c) 2010-2024 Sebastian Bochan
 *
 * License: www.highcharts.com/license
 */function(t){"object"==typeof module&&module.exports?(t.default=t,module.exports=t):"function"==typeof define&&define.amd?define("highcharts/indicators/momentum",["highcharts","highcharts/modules/stock"],function(e){return t(e),t.Highcharts=e,t}):t("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(t){"use strict";var e=t?t._modules:{};function n(e,n,o,r){e.hasOwnProperty(n)||(e[n]=r.apply(null,o),"function"==typeof CustomEvent&&t.win.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:n,module:e[n]}})))}n(e,"Stock/Indicators/Momentum/MomentumIndicator.js",[e["Core/Series/SeriesRegistry.js"],e["Core/Utilities.js"]],function(t,e){var n,o=this&&this.__extends||(n=function(t,e){return(n=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(t,e){t.__proto__=e}||function(t,e){for(var n in e)Object.prototype.hasOwnProperty.call(e,n)&&(t[n]=e[n])})(t,e)},function(t,e){if("function"!=typeof e&&null!==e)throw TypeError("Class extends value "+String(e)+" is not a constructor or null");function o(){this.constructor=t}n(t,e),t.prototype=null===e?Object.create(e):(o.prototype=e.prototype,new o)}),r=t.seriesTypes.sma,s=e.extend,i=e.isArray,u=e.merge;function a(t,e,n,o,r){var s=e[n-1][r]-e[n-o-1][r];return[t[n-1],s]}var c=function(t){function e(){return null!==t&&t.apply(this,arguments)||this}return o(e,t),e.prototype.getValues=function(t,e){var n,o,r=e.period,s=e.index,u=t.xData,c=t.yData,p=c?c.length:0,f=[],h=[],l=[];if(!(u.length<=r)&&i(c[0])){for(n=r+1;n<p;n++)o=a(u,c,n,r,s),f.push(o),h.push(o[0]),l.push(o[1]);return o=a(u,c,n,r,s),f.push(o),h.push(o[0]),l.push(o[1]),{values:f,xData:h,yData:l}}},e.defaultOptions=u(r.defaultOptions,{params:{index:3}}),e}(r);return s(c.prototype,{nameBase:"Momentum"}),t.registerSeriesType("momentum",c),c}),n(e,"masters/indicators/momentum.src.js",[e["Core/Globals.js"]],function(t){return t})});