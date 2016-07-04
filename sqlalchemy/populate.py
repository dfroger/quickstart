import os

from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker

from model import Base, Team, Player

engine = create_engine('sqlite:///foot.db')

if not os.path.isfile('foot.db'):
    Base.metadata.create_all(engine)

france = Team(name='France')
girou = Player(name='Girou', team=france)
payet = Player(name='Payet', team=france)

italie = Team(name='Italie')
buffon = Player(name='buffon', team=italie)
verratti = Player(name='Verratti', team=italie)

Session = sessionmaker(bind=engine)

session = Session()

session.add(france)
session.add(italie)

session.commit()
