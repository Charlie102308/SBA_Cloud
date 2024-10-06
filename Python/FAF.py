import yfinance as yf
import pandas as pd
import os
from subprocess import call
from time import time
Flag = True
while Flag:
    symbol = input('Enter ticker symbol:').upper()
    try:
        ticker = yf.Ticker(symbol)
        ticker_info = ticker.info
        issued_share = round(ticker_info['marketCap'] / ticker_info['currentPrice'] / 1000000, 2)
        float_share = round(ticker.info['floatShares'] / 1000000, 2)
        Float_rate = round(float_share / issued_share, 2)
        print(Float_rate * 100, "%")
    except:
        call('clear' if os.name == 'posix' else 'cls')
        print("No data returned for this ticker")
    Continue = input("Continue? (y/n):")
    if not(Continue == 'y' or Continue == 'Y'):
        Flag = False