import QtQuick 2.0
import QtQml 2.1
import Nutmeg 1.0

/*!
    \ingroup figures
    LinePlot is used for drawing 2D X-Y data plots.
    Axis should be a direct parent. An Axis can contain many Plot choldren.
*/
LineSegmentPlotBase {
    id: linePlot
    width: parent.width
    height: parent.height
    handle: "data"

    property var figure: axis ? axis.figure : null

    canvas: lineCanvas
    LineSegmentPlotCanvas {
        id: lineCanvas
        width: parent.width*scaling
        height: parent.height*scaling
        transform: Scale {
            xScale: 1/lineCanvas.scaling
            yScale: 1/lineCanvas.scaling
        }
    }
}
