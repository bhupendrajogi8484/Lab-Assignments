import pandas as pd

df = pd.read_csv("SMSSpamCollection", delimiter="\t", header=None)
df.head(n=10)
df.columns = ["Class_label", "Message"]
df["Class_label"] = df["Class_label"].apply(lambda x: 1 if x == "spam" else 0)
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(
df["Message"], df["Class_label"], test_size=0.3, random_state=0)

from sklearn.feature_extraction.text import TfidfVectorizer
vectorizer = TfidfVectorizer()
vectorizer.fit(df["Message"])
print(vectorizer.vocabulary_)
new_train_set = vectorizer.transform(x_train)
new_test_set = vectorizer.transform(x_test)
print(new_train_set.shape)
print(new_test_set.shape)
from sklearn.naive_bayes import MultinomialNB

classifier = MultinomialNB()
classifier.fit(new_train_set, y_train)
print("classifier accuracy {:.2f}%".format(classifier.score(new_test_set, y_test) * 100))

email = ["hey Gauri can you get together for lunch","upto 70% discount on exclusive offer",]
new_email = vectorizer.transform(email)
classifier.predict(new_email)
