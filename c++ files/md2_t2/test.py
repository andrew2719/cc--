'''Get the live stock market data using python packages pandas,Numpy and Yfinance, Plotly
[Note Yfinance API needs 3 parameters ,data = yf.download(tickers='OLA', period='4d', 
interval='3m')]
Here OLA is the name of the share,period is 4 days,with an interval of 3 minutes'''

import pandas as pd
import numpy as np
import yfinance as yf

#get the data
data = yf.download('OLA', period='4d', interval='3m')
#create a dataframe
df = pd.DataFrame(data)
#visualize the data
import plotly.express as px
fig = px.line(df, x='Open', y='Close')
fig.show()