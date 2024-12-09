/* *
 *
 *  (c) 2010-2024 Pawel Lysy
 *
 *  License: www.highcharts.com/license
 *
 *  !!!!!!! SOURCE GETS TRANSPILED BY TYPESCRIPT. EDIT TS FILE ONLY. !!!!!!!
 *
 * */
'use strict';
import RenkoPoint from './RenkoPoint.js';
import RenkoSeriesDefaults from './RenkoSeriesDefaults.js';
import SeriesRegistry from '../../Core/Series/SeriesRegistry.js';
import ColumnSeries from '../Column/ColumnSeries.js';
import U from '../../Core/Utilities.js';
const { extend, merge, relativeLength, isNumber } = U;
/* *
 *
 *  Class
 *
 * */
/**
 * The renko series type.
 *
 * @private
 * @class
 * @name Highcharts.seriesTypes.renko
 *
 * @augments Highcharts.seriesTypes.column
 */
class RenkoSeries extends ColumnSeries {
    constructor() {
        super(...arguments);
        this.hasDerivedData = true;
        this.allowDG = false;
        /* *
         *
         *  Functions
         *
         * */
    }
    init() {
        super.init.apply(this, arguments);
        this.renkoData = [];
    }
    setData(data, redraw, animation) {
        this.renkoData = [];
        super.setData(data, redraw, animation, false);
    }
    getXExtremes(xData) {
        this.processData();
        xData = this.getColumn('x', true);
        return {
            min: xData[0],
            max: xData[xData.length - 1]
        };
    }
    getProcessedData() {
        const modified = this.dataTable.modified;
        const processedXData = [];
        const processedYData = [];
        const processedLowData = [];
        const xData = this.getColumn('x', true);
        const yData = this.getColumn('y', true);
        if (!this.renkoData || this.renkoData.length > 0) {
            return {
                modified,
                closestPointRange: 1,
                cropped: false,
                cropStart: 0
            };
        }
        const boxSize = this.options.boxSize;
        const change = isNumber(boxSize) ? boxSize : relativeLength(boxSize, yData[0]);
        const renkoData = [], length = xData.length;
        let prevTrend = 0;
        let prevPrice = yData[0];
        for (let i = 1; i < length; i++) {
            const currentChange = yData[i] - yData[i - 1];
            if (currentChange > change) {
                // Uptrend
                if (prevTrend === 2) {
                    prevPrice += change;
                }
                for (let j = 0; j < currentChange / change; j++) {
                    renkoData.push({
                        x: xData[i] + j,
                        low: prevPrice,
                        y: prevPrice + change,
                        color: this.options.color,
                        upTrend: true
                    });
                    prevPrice += change;
                }
                prevTrend = 1;
            }
            else if (Math.abs(currentChange) > change) {
                if (prevTrend === 1) {
                    prevPrice -= change;
                }
                // Downtrend
                for (let j = 0; j < Math.abs(currentChange) / change; j++) {
                    renkoData.push({
                        x: xData[i] + j,
                        low: prevPrice - change,
                        y: prevPrice,
                        color: this.options.downColor,
                        upTrend: false
                    });
                    prevPrice -= change;
                }
                prevTrend = 2;
            }
        }
        this.renkoData = renkoData;
        for (const point of renkoData) {
            processedXData.push(point.x);
            processedYData.push(point.y);
            processedLowData.push(point.low);
        }
        this.processedData = renkoData;
        modified.setColumn('x', processedXData);
        modified.setColumn('y', processedYData);
        modified.setColumn('low', processedLowData);
        return {
            modified,
            cropped: false,
            cropStart: 0,
            closestPointRange: 1
        };
    }
}
/* *
 *
 *  Static Properties
 *
 * */
RenkoSeries.defaultOptions = merge(ColumnSeries.defaultOptions, RenkoSeriesDefaults);
extend(RenkoSeries.prototype, {
    pointClass: RenkoPoint
});
SeriesRegistry.registerSeriesType('renko', RenkoSeries);
/* *
 *
 *  Default Export
 *
 * */
export default RenkoSeries;