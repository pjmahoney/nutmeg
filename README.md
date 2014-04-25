Nutmeg
======

Nutmeg is multiplatform, multilingual plotting tool. Primarily, it aims to be light, fast, and responsive, and has been designed to be your go to tool when you wish to visualize and play with your data in the experimental phase of a project.

Notable Features:
- Plotting can be asynchronous to program
    + Can visualize the updating of data as your program runs
    + This is also fast
- Responsive panning and zooming of data using mouse or multitouch trackpad
- Lay out figure axes and plots using a more intuitive declarative style (QML)
    + This also makes figure templates easy
- Lay out GUI controls that update parameters, which update the data

Nutmeg in Action
----------------

The following QML file declares a Figure which contains two axes. It uses QML style bindings to ensure they take up a certain percentage of the figure space.

**figure.qml**
```qml
Figure {
    id: fig
    Layouts.Column {
        spacing: 0.05*fig.height
        Axis {
            handle: "axis1"
            Layout.preferredheight: 0.65*fig.height
            LinePlot { handle: "data" }
        }
        Axis {
            handle: "axis2"
            Layout.preferredHeight: 0.3*fig.height
            LinePlot { handle: "data" }
        }
    }
}
```

From Python, data can be plotted like so:

```python
import nutmeg
from numpy import sin, cos, pi

nut = nutmeg.Nutmeg()

x = [ 0.01*n for n in range(100) ]
y1 = [ sin(10*pi*t) for t in x ]
y2 = [ 10*pi*cos(10*pi*t) for t in x ]

fig = nut.figure("myFigure", figure.qml")

fig.set("axis1.data", {'x': x, 'y': y1})
fig.set("axis2.data", {'x': x, 'y': y2})
```

Result:
> screenshot


The Architecture
----------------

The Nutmeg core is a stand alone executable, and other programs can draw figures by sending the appropriate data wrapped up in JSON via sockets. The socket interface is built on the wonderful [ZMQ](http://zeromq.org/) enabling Nutmeg to support multiple platforms and languages.

The end user could in fact plot using the interface as it is, but a language-side API can simplify the process greatly. Therefore typically a user should become familiar with two interfaces: the QML-style Figure layout, and a language specific Nutmeg library for sending the Figure layout and updating its data.


Building
--------

### Requirements
- Qt 5.3 or higher
- [ZMQ](http://zeromq.org/intro:get-the-software) 3.2.x (4.0.x should technically work, but is untested)

### Unix
Before building, ensure that in `nutmeg.pro` the INCLUDEPATH and QMAKE_LIBDIR point to the include path and
library path for [zmq](http://zeromq.org/intro:get-the-software). If zmq has been built with the default
configuration in your favourite flavour of Unix, the default `nutmeg.pro` values should be fine.

### Windows
Need to try that yet. Let me know!

Goals
-----


Non-Goals
---------