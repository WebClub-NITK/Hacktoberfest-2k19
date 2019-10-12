'King_Queen_Man_Woman.txt' contains 300-dimensional GloVe word embeddings for the words 'king', 'queen', 'man' and 'woman'. To extract these embeddings, use this snippet of Python code:

emb_file=open('King_Queen_Man_Woman.txt','r')
embeddings={}
for line in emb_file:
    vals=line.split()
    embeddings[vals[0]]=np.asarray(vals[1:],dtype=np.float32)