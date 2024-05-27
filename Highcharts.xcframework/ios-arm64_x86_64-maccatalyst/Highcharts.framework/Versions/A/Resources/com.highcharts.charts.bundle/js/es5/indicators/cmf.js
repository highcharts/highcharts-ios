!/**
 * Highstock JS v11.4.3 (2024-05-22)
 *
 * (c) 2010-2024 Highsoft AS
 * Author: Sebastian Domas
 *
 * License: www.highcharts.com/license
 */function(t){"object"==typeof module&&module.exports?(t.default=t,module.exports=t):"function"==typeof define&&define.amd?define("highcharts/indicators/cmf",["highcharts","highcharts/modules/stock"],function(e){return t(e),t.Highcharts=e,t}):t("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(t){"use strict";var e=t?t._modules:{};function n(t,e,n,o){t.hasOwnProperty(e)||(t[e]=o.apply(null,n),"function"==typeof CustomEvent&&window.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:e,module:t[e]}})))}n(e,"Stock/Indicators/CMF/CMFIndicator.js",[e["Core/Series/SeriesRegistry.js"],e["Core/Utilities.js"]],function(t,e){var n,o=this&&this.__extends||(n=function(t,e){return(n=Object.setPrototypeOf||({__proto__:[]})instanceof Array&&function(t,e){t.__proto__=e}||function(t,e){for(var n in e)Object.prototype.hasOwnProperty.call(e,n)&&(t[n]=e[n])})(t,e)},function(t,e){if("function"!=typeof e&&null!==e)throw TypeError("Class extends value "+String(e)+" is not a constructor or null");function o(){this.constructor=t}n(t,e),t.prototype=null===e?Object.create(e):(o.prototype=e.prototype,new o)}),r=t.seriesTypes.sma,i=e.merge,s=function(t){function e(){var e=null!==t&&t.apply(this,arguments)||this;return e.nameBase="Chaikin Money Flow",e}return o(e,t),e.prototype.isValid=function(){var t=this.chart,e=this.options,n=this.linkedParent,o=this.volumeSeries||(this.volumeSeries=t.get(e.params.volumeSeriesID)),r=n&&n.yData&&4===n.yData[0].length;function i(t){return t.xData&&t.xData.length>=e.params.period}return!!(n&&o&&i(n)&&i(o)&&r)},e.prototype.getValues=function(t,e){if(this.isValid())return this.getMoneyFlow(t.xData,t.yData,this.volumeSeries.yData,e.period)},e.prototype.getMoneyFlow=function(t,e,n,o){var r,i,s=e.length,u=[],a=[],l=[],c=[],p=-1,h=0,f=0;function d(t,e){var n=t[1],o=t[2],i=t[3];return null!==e&&null!==n&&null!==o&&null!==i&&n!==o?(i-o-(n-i))/(n-o)*e:(p=r,null)}if(o>0&&o<=s){for(r=0;r<o;r++)u[r]=d(e[r],n[r]),h+=n[r],f+=u[r];for(a.push(t[r-1]),l.push(r-p>=o&&0!==h?f/h:null),c.push([a[0],l[0]]);r<s;r++)u[r]=d(e[r],n[r]),h-=n[r-o],h+=n[r],f-=u[r-o],f+=u[r],i=[t[r],r-p>=o?f/h:null],a.push(i[0]),l.push(i[1]),c.push([i[0],i[1]])}return{values:c,xData:a,yData:l}},e.defaultOptions=i(r.defaultOptions,{params:{index:void 0,volumeSeriesID:"volume"}}),e}(r);return t.registerSeriesType("cmf",s),s}),n(e,"masters/indicators/cmf.src.js",[e["Core/Globals.js"]],function(t){return t})});