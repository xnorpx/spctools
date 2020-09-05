from spctools import plot, hold, show

def test_plot():
    plot(range(4), range(4))
    hold(True)
    plot(range(4), [0,1,1,3])
    show()

if __name__ == "__main__":
    test_plot()
