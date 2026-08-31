import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> list:
    return [players.shape[0], players.shape[1]]