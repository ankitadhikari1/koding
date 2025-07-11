import pandas as pd

def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame:
    store1 = products[~products['store1'].isnull()][['product_id','store1']].rename(columns={'store1':'price'})
    store1['store'] = 'store1'
    store2 = products[~products['store2'].isnull()][['product_id','store2']].rename(columns={'store2':'price'})
    store2['store'] = 'store2'
    store3 = products[~products['store3'].isnull()][['product_id','store3']].rename(columns={'store3':'price'})
    store3['store'] = 'store3'

    return pd.concat([store1,store2,store3])