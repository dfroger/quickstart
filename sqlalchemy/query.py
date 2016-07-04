from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker

from model import Team, Player

engine = create_engine('sqlite:///foot.db')

Session = sessionmaker(bind=engine)

session = Session()

payet = session.query(Player).filter(Player.name == 'Payet').first()
print(payet.name, payet.team)

france = session.query(Team).filter(Team.name == 'France').first()
print(france.name, france.players)
