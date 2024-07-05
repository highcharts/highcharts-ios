!/**
 * Highcharts JS v11.4.5 (2024-07-04)
 *
 * Data module
 *
 * (c) 2012-2024 Torstein Honsi
 *
 * License: www.highcharts.com/license
 */function(e){"object"==typeof module&&module.exports?(e.default=e,module.exports=e):"function"==typeof define&&define.amd?define("highcharts/modules/data",["highcharts"],function(t){return e(t),e.Highcharts=t,e}):e("undefined"!=typeof Highcharts?Highcharts:void 0)}(function(e){"use strict";var t=e?e._modules:{};function r(t,r,n,o){t.hasOwnProperty(r)||(t[r]=o.apply(null,n),"function"==typeof CustomEvent&&e.win.dispatchEvent(new CustomEvent("HighchartsModuleLoaded",{detail:{path:r,module:t[r]}})))}r(t,"Core/HttpUtilities.js",[t["Core/Globals.js"],t["Core/Utilities.js"]],function(e,t){var r=this&&this.__assign||function(){return(r=Object.assign||function(e){for(var t,r=1,n=arguments.length;r<n;r++)for(var o in t=arguments[r])Object.prototype.hasOwnProperty.call(t,o)&&(e[o]=t[o]);return e}).apply(this,arguments)},n=e.win,o=t.discardElement,a=t.objectEach,i={ajax:function(e){var t={json:"application/json",xml:"application/xml",text:"text/plain",octet:"application/octet-stream"},r=new XMLHttpRequest;function n(t,r){e.error&&e.error(t,r)}if(!e.url)return!1;r.open((e.type||"get").toUpperCase(),e.url,!0),e.headers&&e.headers["Content-Type"]||r.setRequestHeader("Content-Type",t[e.dataType||"json"]||t.text),a(e.headers,function(e,t){r.setRequestHeader(t,e)}),e.responseType&&(r.responseType=e.responseType),r.onreadystatechange=function(){var t;if(4===r.readyState){if(200===r.status){if("blob"!==e.responseType&&(t=r.responseText,"json"===e.dataType))try{t=JSON.parse(t)}catch(e){if(e instanceof Error)return n(r,e)}return e.success&&e.success(t,r)}n(r,r.responseText)}},e.data&&"string"!=typeof e.data&&(e.data=JSON.stringify(e.data)),r.send(e.data)},getJSON:function(e,t){i.ajax({url:e,success:t,dataType:"json",headers:{"Content-Type":"text/plain"}})},post:function(e,t,i){var s=new n.FormData;a(t,function(e,t){s.append(t,e)}),s.append("b64","true");var l=t.filename,u=t.type;return n.fetch(e,r({method:"POST",body:s},i)).then(function(e){e.ok&&e.text().then(function(e){var t=document.createElement("a");t.href="data:".concat(u,";base64,").concat(e),t.download=l,t.click(),o(t)})})}};return i}),r(t,"Extensions/Data.js",[t["Core/Chart/Chart.js"],t["Core/Defaults.js"],t["Core/Globals.js"],t["Core/HttpUtilities.js"],t["Core/Series/Point.js"],t["Core/Series/SeriesRegistry.js"],t["Core/Utilities.js"]],function(e,t,r,n,o,a,i){var s=t.getOptions,l=r.doc,u=n.ajax,d=a.seriesTypes,h=i.addEvent,c=i.defined,p=i.extend,f=i.fireEvent,m=i.isNumber,g=i.merge,v=i.objectEach,y=i.pick,x=i.splat;function C(e){return!!(e&&(e.rowsURL||e.csvURL||e.columnsURL))}var T=function(){function e(t,r,n){void 0===r&&(r={}),this.rowsToColumns=e.rowsToColumns,this.dateFormats={"YYYY/mm/dd":{regex:/^(\d{4})[\-\/\.](\d{1,2})[\-\/\.](\d{1,2})$/,parser:function(e){return e?Date.UTC(+e[1],e[2]-1,+e[3]):NaN}},"dd/mm/YYYY":{regex:/^(\d{1,2})[\-\/\.](\d{1,2})[\-\/\.](\d{4})$/,parser:function(e){return e?Date.UTC(+e[3],e[2]-1,+e[1]):NaN},alternative:"mm/dd/YYYY"},"mm/dd/YYYY":{regex:/^(\d{1,2})[\-\/\.](\d{1,2})[\-\/\.](\d{4})$/,parser:function(e){return e?Date.UTC(+e[3],e[1]-1,+e[2]):NaN}},"dd/mm/YY":{regex:/^(\d{1,2})[\-\/\.](\d{1,2})[\-\/\.](\d{2})$/,parser:function(e){if(!e)return NaN;var t=new Date,r=+e[3];return r>t.getFullYear()-2e3?r+=1900:r+=2e3,Date.UTC(r,e[2]-1,+e[1])},alternative:"mm/dd/YY"},"mm/dd/YY":{regex:/^(\d{1,2})[\-\/\.](\d{1,2})[\-\/\.](\d{2})$/,parser:function(e){return e?Date.UTC(+e[3]+2e3,e[1]-1,+e[2]):NaN}}},this.chart=n,this.chartOptions=r,this.options=t,this.rawColumns=[],this.init(t,r,n)}return e.data=function(t,r,n){return void 0===r&&(r={}),new e(t,r,n)},e.rowsToColumns=function(e){var t,r,n,o,a;if(e)for(t=0,a=[],r=e.length;t<r;t++)for(n=0,o=e[t].length;n<o;n++)a[n]||(a[n]=[]),a[n][t]=e[t][n];return a},e.prototype.init=function(e,t,r){var n,o=e.decimalPoint;t&&(this.chartOptions=t),r&&(this.chart=r),"."!==o&&","!==o&&(o=void 0),this.options=e,this.columns=e.columns||this.rowsToColumns(e.rows)||[],this.firstRowAsNames=y(e.firstRowAsNames,this.firstRowAsNames,!0),this.decimalRegex=o&&RegExp("^(-?[0-9]+)"+o+"([0-9]+)$"),void 0!==this.liveDataTimeout&&clearTimeout(this.liveDataTimeout),this.rawColumns=[],this.columns.length&&(this.dataFound(),n=!C(e)),n||(n=this.fetchLiveData()),n||(n=!!this.parseCSV().length),n||(n=!!this.parseTable().length),n||(n=this.parseGoogleSpreadsheet()),!n&&e.afterComplete&&e.afterComplete()},e.prototype.getColumnDistribution=function(){var e,t=this.chartOptions,r=this.options,n=[],o=function(e){return(d[e||"line"].prototype.pointArrayMap||[0]).length},a=function(e){return d[e||"line"].prototype.pointArrayMap},i=t&&t.chart&&t.chart.type,s=[],l=[],u=r&&r.seriesMapping||t&&t.series&&t.series.map(function(){return{x:0}})||[],h=0;(t&&t.series||[]).forEach(function(e){s.push(o(e.type||i))}),u.forEach(function(e){n.push(e.x||0)}),0===n.length&&n.push(0),u.forEach(function(r){var n=new R,u=s[h]||o(i),d=(t&&t.series||[])[h]||{},p=a(d.type||i),f=p||["y"];for((c(r.x)||d.isCartesian||!p)&&n.addColumnReader(r.x,"x"),v(r,function(e,t){"x"!==t&&n.addColumnReader(e,t)}),e=0;e<u;e++)n.hasReader(f[e])||n.addColumnReader(void 0,f[e]);l.push(n),h++});var p=a(i);void 0===p&&(p=["y"]),this.valueCount={global:o(i),xColumns:n,individual:s,seriesBuilders:l,globalPointArrayMap:p}},e.prototype.dataFound=function(){this.options.switchRowsAndColumns&&(this.columns=this.rowsToColumns(this.columns)),this.getColumnDistribution(),this.parseTypes(),!1!==this.parsed()&&this.complete()},e.prototype.parseCSV=function(e){var t,r,n,o,a,i=this,s=this.columns=[],l=e||this.options,u=void 0!==l.startColumn&&l.startColumn?l.startColumn:0,d=l.endColumn||Number.MAX_VALUE,h=[],c={",":0,";":0,"	":0},p=l.csv,m=void 0!==l.startRow&&l.startRow?l.startRow:0,g=l.endRow||Number.MAX_VALUE,v=0;if(p&&l.beforeParse&&(p=l.beforeParse.call(this,p)),p){(a=p.replace(/\r\n/g,"\n").replace(/\r/g,"\n").split(l.lineDelimiter||"\n"),(!m||m<0)&&(m=0),(!g||g>=a.length)&&(g=a.length-1),l.itemDelimiter)?o=l.itemDelimiter:(o=null,t=0,r=0,n=!1,a.some(function(e,n){var o,a,i,s=!1,l="";if(n>13)return!0;for(var u=0;u<e.length;u++){if(o=e[u],a=e[u+1],i=e[u-1],"#"===o)return;if('"'===o){if(s){if('"'!==i&&'"'!==a){for(;" "===a&&u<e.length;)a=e[++u];void 0!==c[a]&&c[a]++,s=!1}}else s=!0}else void 0!==c[o]?(isNaN(Date.parse(l=l.trim()))?(isNaN(l)||!isFinite(l))&&c[o]++:c[o]++,l=""):l+=o;","===o&&r++,"."===o&&t++}}),c[";"]>c[","]?n=";":(c[","],c[";"],n=","),l.decimalPoint||(t>r?l.decimalPoint=".":l.decimalPoint=",",i.decimalRegex=RegExp("^(-?[0-9]+)"+l.decimalPoint+"([0-9]+)$")),o=n);var y=0;for(v=m;v<=g;v++)"#"===a[v][0]?y++:function(e,t,r,n){var a=0,i="",c="",p="",f="",m=0,g=0;function v(t){i=e[t],c=e[t-1],p=e[t+1]}function y(e){h.length<g+1&&h.push([e]),h[g][h[g].length-1]!==e&&h[g].push(e)}function x(){if(u>m||m>d){++m,f="";return}l.columnTypes||(!isNaN(parseFloat(f))&&isFinite(f)?(f=parseFloat(f),y("number")):isNaN(Date.parse(f))?y("string"):(f=f.replace(/\//g,"-"),y("date"))),s.length<g+1&&s.push([]),s[g][t]=f,f="",++g,++m}if(e.trim().length&&"#"!==e.trim()[0]){for(;a<e.length;a++)if(v(a),'"'===i)for(v(++a);a<e.length&&('"'!==i||'"'===c||'"'===p);)('"'!==i||'"'===i&&'"'!==c)&&(f+=i),v(++a);else i===o?x():f+=i;x()}}(a[v],v-m-y);(!l.columnTypes||0===l.columnTypes.length)&&h.length&&h[0].length&&"date"===h[0][1]&&!l.dateFormat&&(l.dateFormat=function(e,t){var r,n,o,a="YYYY/mm/dd",s=[],u=[],d=[],h=0,c=!1;for((!t||t>e.length)&&(t=e.length);h<t;h++)if(void 0!==e[h]&&e[h]&&e[h].length)for(o=0,r=e[h].trim().replace(/\//g," ").replace(/\-/g," ").replace(/\./g," ").split(" "),d=["","",""];o<r.length;o++)o<d.length&&(r[o]=parseInt(r[o],10),r[o]&&(u[o]=!u[o]||u[o]<r[o]?r[o]:u[o],void 0!==s[o]?s[o]!==r[o]&&(s[o]=!1):s[o]=r[o],r[o]>31?r[o]<100?d[o]="YY":d[o]="YYYY":r[o]>12&&r[o]<=31?(d[o]="dd",c=!0):d[o].length||(d[o]="mm")));if(c){for(o=0;o<s.length;o++)!1!==s[o]?u[o]>12&&"YY"!==d[o]&&"YYYY"!==d[o]&&(d[o]="YY"):u[o]>12&&"mm"===d[o]&&(d[o]="dd");return(3===d.length&&"dd"===d[1]&&"dd"===d[2]&&(d[2]="YY"),n=d.join("/"),(l.dateFormats||i.dateFormats)[n])?n:(f("deduceDateFailed"),a)}return a}(s[0])),this.dataFound()}return s},e.prototype.parseTable=function(){var e=this.options,t=this.columns||[],r=e.startRow||0,n=e.endRow||Number.MAX_VALUE,o=e.startColumn||0,a=e.endColumn||Number.MAX_VALUE;if(e.table){var i=e.table;"string"==typeof i&&(i=l.getElementById(i)),[].forEach.call(i.getElementsByTagName("tr"),function(e,i){i>=r&&i<=n&&[].forEach.call(e.children,function(e,n){var s=t[n-o],l=1;if(("TD"===e.tagName||"TH"===e.tagName)&&n>=o&&n<=a)for(t[n-o]||(t[n-o]=[]),t[n-o][i-r]=e.innerHTML;i-r>=l&&void 0===s[i-r-l];)s[i-r-l]=null,l++})}),this.dataFound()}return t},e.prototype.fetchLiveData=function(){var e=this,t=this.chart,r=this.options,n=r.enablePolling,o=g(r),a=0,i=1e3*(r.dataRefreshRate||2);return!!C(r)&&(i<1e3&&(i=1e3),delete r.csvURL,delete r.rowsURL,delete r.columnsURL,function s(l){function d(o,d,h){if(!o||!/^(http|\/|\.\/|\.\.\/)/.test(o))return o&&r.error&&r.error("Invalid URL"),!1;function c(){n&&t.liveDataURL===o&&(e.liveDataTimeout=setTimeout(s,i))}return l&&(clearTimeout(e.liveDataTimeout),t.liveDataURL=o),u({url:o,dataType:h||"json",success:function(e){t&&t.series&&d(e),c()},error:function(e,t){return++a<3&&c(),r.error&&r.error(t,e)}}),!0}d(o.csvURL,function(e){t.update({data:{csv:e}})},"text")||d(o.rowsURL,function(e){t.update({data:{rows:e}})})||d(o.columnsURL,function(e){t.update({data:{columns:e}})})}(!0),C(r))},e.prototype.parseGoogleSpreadsheet=function(){var e=this,t=this.options,r=t.googleSpreadsheetKey,n=this.chart,o=Math.max(1e3*(t.dataRefreshRate||2),4e3),a=function(){if(t.googleSpreadsheetRange)return t.googleSpreadsheetRange;var e="ABCDEFGHIJKLMNOPQRSTUVWXYZ",r=(e.charAt(t.startColumn||0)||"A")+((t.startRow||0)+1),n=e.charAt(y(t.endColumn,-1))||"ZZ";return c(t.endRow)&&(n+=t.endRow+1),"".concat(r,":").concat(n)};return r&&(delete t.googleSpreadsheetKey,function n(i){u({url:["https://sheets.googleapis.com/v4/spreadsheets",r,"values",a(),"?alt=json&majorDimension=COLUMNS&valueRenderOption=UNFORMATTED_VALUE&dateTimeRenderOption=FORMATTED_STRING&key="+t.googleAPIKey].join("/"),dataType:"json",success:function(r){i(r),t.enablePolling&&(e.liveDataTimeout=setTimeout(function(){n(i)},o))},error:function(e,r){return t.error&&t.error(r,e)}})}(function(t){var r=t.values;if(!r||0===r.length)return!1;var o=r.reduce(function(e,t){return Math.max(e,t.length)},0);r.forEach(function(e){for(var t=0;t<o;t++)void 0===e[t]&&(e[t]=null)}),n&&n.series?n.update({data:{columns:r}}):(e.columns=r,e.dataFound())})),!1},e.prototype.trim=function(e,t){return"string"==typeof e&&(e=e.replace(/^\s+|\s+$/g,""),t&&/[\d\s]+/.test(e)&&(e=e.replace(/\s/g,"")),this.decimalRegex&&(e=e.replace(this.decimalRegex,"$1.$2"))),e},e.prototype.parseTypes=function(){for(var e=this.columns||[],t=e.length;t--;)this.parseColumn(e[t],t)},e.prototype.parseColumn=function(e,t){var r,n,o,a,i,s,l,u=this.rawColumns,d=this.columns,h=this.firstRowAsNames,p=-1!==this.valueCount.xColumns.indexOf(t),f=[],g=this.chartOptions,v=(this.options.columnTypes||[])[t],y=p&&g&&g.xAxis&&"category"===x(g.xAxis)[0].type||"string"===v,C=c(e.name),T=e.length;for(u[t]||(u[t]=[]);T--;)r=f[T]||e[T],o=this.trim(r),n=parseFloat(a=this.trim(r,!0)),void 0===u[t][T]&&(u[t][T]=o),y||0===T&&h&&!C?e[T]=""+o:+a===n?(e[T]=n,n>31536e6&&"float"!==v?e.isDatetime=!0:e.isNumeric=!0,void 0!==e[T+1]&&(l=n>e[T+1])):(o&&o.length&&(i=this.parseDate(r)),p&&m(i)&&"float"!==v?(f[T]=r,e[T]=i,e.isDatetime=!0,void 0!==e[T+1]&&((s=i>e[T+1])!==l&&void 0!==l&&(this.alternativeFormat?(this.dateFormat=this.alternativeFormat,T=e.length,this.alternativeFormat=this.dateFormats[this.dateFormat].alternative):e.unsorted=!0),l=s)):(e[T]=""===o?null:o,0!==T&&(e.isDatetime||e.isNumeric)&&(e.mixed=!0)));if(p&&e.mixed&&(d[t]=u[t]),p&&l&&this.options.sort)for(t=0;t<d.length;t++)d[t].reverse(),h&&d[t].unshift(d[t].pop())},e.prototype.parseDate=function(e){var t,r,n,o,a=this.options.parseDate,i=this.options.dateFormat||this.dateFormat;if(a)t=a(e);else if("string"==typeof e){if(i)(n=this.dateFormats[i])||(n=this.dateFormats["YYYY/mm/dd"]),(o=e.match(n.regex))&&(t=n.parser(o));else for(r in this.dateFormats)if(n=this.dateFormats[r],o=e.match(n.regex)){this.dateFormat=i=r,this.alternativeFormat=n.alternative,t=n.parser(o);break}!o&&(e.match(/:.+(GMT|UTC|[Z+\-])/)&&(e=e.replace(/\s*(?:GMT|UTC)?([+\-])(\d\d)(\d\d)$/,"$1$2:$3").replace(/(?:\s+|GMT|UTC)([+\-])/,"$1").replace(/(\d)\s*(?:GMT|UTC|Z)$/,"$1+00:00")),"object"==typeof(o=Date.parse(e))&&null!==o&&o.getTime?t=o.getTime()-6e4*o.getTimezoneOffset():m(o)&&(t=o-6e4*new Date(o).getTimezoneOffset()))}return t},e.prototype.getData=function(){if(this.columns)return this.rowsToColumns(this.columns).slice(1)},e.prototype.parsed=function(){if(this.options.parsed)return this.options.parsed.call(this,this.columns)},e.prototype.complete=function(){var e,t,r,n,o,a,i,s,l,u,d,h,p=this.columns,f=this.options,m=[];if([].length=p.length,f.complete||f.afterComplete){if(this.firstRowAsNames)for(n=0;n<p.length;n++){var g=p[n];c(g.name)||(g.name=y(g.shift(),"").toString())}for(i=0,t=[],u=function(e,t){var r,n,o,a=[],i=[];for(n=0;n<e;n+=1)a.push(!0);for(r=0;r<t.length;r+=1)for(n=0,o=t[r].getReferencedColumnIndexes();n<o.length;n+=1)a[o[n]]=!1;for(n=0;n<a.length;n+=1)a[n]&&i.push(n);return i}(p.length,this.valueCount.seriesBuilders);i<this.valueCount.seriesBuilders.length;i++)(l=this.valueCount.seriesBuilders[i]).populateColumns(u)&&m.push(l);for(;u.length>0;){for((l=new R).addColumnReader(0,"x"),-1!==(h=u.indexOf(0))&&u.splice(h,1),n=0;n<this.valueCount.global;n++)l.addColumnReader(void 0,this.valueCount.globalPointArrayMap[n]);l.populateColumns(u)&&m.push(l)}if(m.length>0&&m[0].readers.length>0&&void 0!==(d=p[m[0].readers[0].columnIndex])&&(d.isDatetime?e="datetime":d.isNumeric||(e="category")),"category"===e)for(i=0;i<m.length;i++)for(a=0,l=m[i];a<l.readers.length;a++)"x"===l.readers[a].configName&&(l.readers[a].configName="name");for(i=0;i<m.length;i++){for(o=0,l=m[i],r=[];o<p[0].length;o++)r[o]=l.read(p,o);t[i]={data:r},l.name&&(t[i].name=l.name),"category"===e&&(t[i].turboThreshold=0)}s={series:t},e&&(s.xAxis={type:e},"category"===e&&(s.xAxis.uniqueNames=!1)),f.complete&&f.complete(s),f.afterComplete&&f.afterComplete(s)}},e.prototype.update=function(e,t){var r=this.chart,n=r.options;e&&(e.afterComplete=function(e){e&&(e.xAxis&&r.xAxis[0]&&e.xAxis.type===r.xAxis[0].options.type&&delete e.xAxis,r.update(e,t,!0))},g(!0,n.data,e),n.data&&n.data.googleSpreadsheetKey&&!e.columns&&delete n.data.columns,this.init(n.data))},e}();h(e,"init",function(e){var t=this,r=e.args[1],n=s().data,o=e.args[0]||{};if((n||o&&o.data)&&!t.hasDataDef){t.hasDataDef=!0;var a=g(n,o.data);t.data=new T(p(a,{afterComplete:function(e){var n,a;if(Object.hasOwnProperty.call(o,"series")){if("object"==typeof o.series)for(n=Math.max(o.series.length,e&&e.series?e.series.length:0);n--;)a=o.series[n]||{},o.series[n]=g(a,e&&e.series?e.series[n]:{});else delete o.series}o=g(e,o),t.init(o,r)}}),o,t),e.preventDefault()}});var R=function(){function e(){this.readers=[],this.pointIsArray=!0}return e.prototype.populateColumns=function(e){var t=!0;return this.readers.forEach(function(t){void 0===t.columnIndex&&(t.columnIndex=e.shift())}),this.readers.forEach(function(e){void 0===e.columnIndex&&(t=!1)}),t},e.prototype.read=function(e,t){var r=this.pointIsArray,n=r?[]:{};if(this.readers.forEach(function(a){var i=e[a.columnIndex][t];r?n.push(i):a.configName.indexOf(".")>0?o.prototype.setNestedProperty(n,i,a.configName):n[a.configName]=i}),void 0===this.name&&this.readers.length>=2){var a=[];this.readers.forEach(function(e){("x"===e.configName||"name"===e.configName||"y"===e.configName)&&void 0!==e.columnIndex&&a.push(e.columnIndex)}),a.length>=2&&(a.shift(),a.sort(function(e,t){return e-t})),this.name=e[y(a.shift(),0)].name}return n},e.prototype.addColumnReader=function(e,t){this.readers.push({columnIndex:e,configName:t}),"x"===t||"y"===t||void 0===t||(this.pointIsArray=!1)},e.prototype.getReferencedColumnIndexes=function(){var e,t,r=[];for(e=0;e<this.readers.length;e+=1)void 0!==(t=this.readers[e]).columnIndex&&r.push(t.columnIndex);return r},e.prototype.hasReader=function(e){var t;for(t=0;t<this.readers.length;t+=1)if(this.readers[t].configName===e)return!0},e}();return T}),r(t,"masters/modules/data.src.js",[t["Core/Globals.js"],t["Core/HttpUtilities.js"],t["Extensions/Data.js"]],function(e,t,r){return e.Data=e.Data||r,e.HttpUtilities=e.HttpUtilities||t,e.ajax=e.HttpUtilities.ajax,e.data=e.Data.data,e.getJSON=e.HttpUtilities.getJSON,e.post=e.HttpUtilities.post,e})});