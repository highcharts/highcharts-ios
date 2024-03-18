!/**
 * Highstock JS v11.4.0 (2024-03-04)
 *
 * Indicator series type for Highcharts Stock
 *
 * (c) 2010-2024 Paweł Dalek
 *
 * License: www.highcharts.com/license
 */function(t){"object"==typeof module&&module.exports?(t.default=t,module.exports=t):"function"==typeof define&&define.amd?define("highcharts/indicators/vwap",["highcharts","highcharts/modules/stock"],function(e){return t(e),t.Highcharts=e,t}):t("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(t){"use strict";var e=t?t._modules:{};function o(t,e,o,r){t.hasOwnProperty(e)||(t[e]=r.apply(null,o),"function"==typeof CustomEvent&&window.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:e,module:t[e]}})))}o(e,"Stock/Indicators/VWAP/VWAPIndicator.js",[e["Core/Series/SeriesRegistry.js"],e["Core/Utilities.js"]],function(t,e){var o,r=this&&this.__extends||(o=function(t,e){return(o=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(t,e){t.__proto__=e}||function(t,e){for(var o in e)Object.prototype.hasOwnProperty.call(e,o)&&(t[o]=e[o])})(t,e)},function(t,e){if("function"!=typeof e&&null!==e)throw TypeError("Class extends value "+String(e)+" is not a constructor or null");function r(){this.constructor=t}o(t,e),t.prototype=null===e?Object.create(e):(r.prototype=e.prototype,new r)}),n=t.seriesTypes.sma,s=e.error,i=e.isArray,u=e.merge,a=function(t){function e(){return null!==t&&t.apply(this,arguments)||this}return r(e,t),e.prototype.getValues=function(t,e){var o,r=t.chart,n=t.xData,u=t.yData,a=e.period,c=!0;if(!(o=r.get(e.volumeSeriesID))){s("Series "+e.volumeSeriesID+" not found! Check `volumeSeriesID`.",!0,r);return}return i(u[0])||(c=!1),this.calculateVWAPValues(c,n,u,o,a)},e.prototype.calculateVWAPValues=function(t,e,o,r,n){var s,i,u,a,c,p,l=r.yData,f=r.xData.length,h=e.length,d=[],y=[],v=[],m=[],g=[];for(c=0,s=h<=f?h:f,p=0;c<s;c++)i=(t?(o[c][1]+o[c][2]+o[c][3])/3:o[c])*l[c],u=p?d[c-1]+i:i,a=p?y[c-1]+l[c]:l[c],d.push(u),y.push(a),g.push([e[c],u/a]),v.push(g[c][0]),m.push(g[c][1]),++p===n&&(p=0);return{values:g,xData:v,yData:m}},e.defaultOptions=u(n.defaultOptions,{params:{index:void 0,period:30,volumeSeriesID:"volume"}}),e}(n);return t.registerSeriesType("vwap",a),a}),o(e,"masters/indicators/vwap.src.js",[e["Core/Globals.js"]],function(t){return t})});