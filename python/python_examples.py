import Nutmeg
from Nutmeg import Updater

from scipy import ndimage
import time
import numpy as np


def applyBlur(dataIn, sigma):
    return ndimage.gaussian_filter1d(dataIn, sigma, axis=1)


def _testParams():
    Nutmeg.init()
    fig = Nutmeg.figure('fig', 'figure1.qml')

    print "Sending GUI..."
    success = fig.setGui('gui1.qml')

    N = 100
    data = np.random.standard_normal((3, N*10))
    data2 = np.random.standard_normal((3, N))

    update = lambda params: applyBlur(data, params['sigma'])
    update2 = lambda params: applyBlur(data2, params['sigma'])

    fig.set('ax[:].blue.x', np.arange(N*10,dtype=float)/10)
    fig.set('ax[:].red.x', np.arange(N, dtype=float))
    fig.set('ax[:].blue.y', Updater(['sigma'], update=update))
    fig.set('ax[:].red.y', Updater(['sigma'], update=update2))
    # for i in range(100):
    #     fig.set('ax[:].red', update2({'sigma': i*0.05}))
    #     time.sleep(0.025)
    print("Data set")


def _testBasic():
    print "Init"
    Nutmeg.init()
    print "Sending Figure"
    fig = Nutmeg.figure('fig', "figure1.qml")
    print "Sending Data"
    fig.set('ax[1].red.y', np.random.standard_normal(10))


def _testImages():
    import cv2
    Nutmeg.init()
    fig = Nutmeg.figure('fig', "figureIm.qml")

    im = open("img.jpg")
    imData = im.read()
    fig.set('ax.im.binary', imData)


def _testDelta():
    Nutmeg.init()
    fig = Nutmeg.figure('fig', 'figure1.qml')
    fig.set('ax[1].red.y', np.random.standard_normal(10))
    fig.set('ax[1].red.y[5]', -10)


def _testGrid():
    Nutmeg.init()
    fig = Nutmeg.figure('fig', 'figureGrid.qml')
    fig.set('ax[1].red.y', np.random.standard_normal(10))


def _testFonts():
    Nutmeg.init()
    fig = Nutmeg.figure('fig', 'figureFont.qml')
    fig.set('ax[1].red.y', np.random.standard_normal(10))
    # fig.set('ax[1].title', "Axis2")
    for i in range(3):
        fig.set('ax[' + str(i) + '].title', "Axis" + str(i+1))

def _testValidateHandle():
    Nutmeg.init()
    fig = Nutmeg.figure('fig', 'figure_single.qml')
    print(Nutmeg.isValidHandle('fig.ax.redPlot'))

def _testButton():
    Nutmeg.init()
    fig = Nutmeg.figure('fig', 'figure_single.qml')
    fig.setGui('gui1.qml')

    print (fig.parameters)
    time.sleep(0.1)
    buttonParam = fig.parameter("button")

    while True:
        if buttonParam.changed:
            changes = buttonParam.changed
            print("Button: %d (clicked %d times)" % (changes, buttonParam.read()))
            break
        time.sleep(0.1)


if __name__ == '__main__':
    # _testParams()
    # _testBasic()
    # _testDelta()
    # _testImages()
    # _testGrid()
    # _testFonts()
    # _testValidateHandle()
    _testButton()
    # _testFloats()
    # print toQmlObject({'xdata': {0:[1,2,3], 1:[[4],5,6], 2:np.eye(3)}, 'ydata': range(4)})
