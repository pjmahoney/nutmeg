import QtQuick 2.0
import Graphr 1.0

FigureBase {
    objectName: "figure"
    width: parent.width
    height: parent.height

    handle: "fig"

    property int tabIndex: -1
    property var guiItem: null
}
