from sqlalchemy import Integer, ForeignKey, String, Column
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import relationship

Base = declarative_base()

class Team(Base):
    __tablename__ = 'team'
    id = Column(Integer, primary_key=True)
    name = Column(String)

    def __repr__(self):
        return self.name

class Player(Base):
    __tablename__ = 'player'
    id = Column(Integer, primary_key=True)
    name = Column(String)

    team_id = Column(Integer, ForeignKey('team.id'), nullable=True)
    team = relationship('Team', backref='players')

    def __repr__(self):
        return "Player(" \
                   "name='{self.name}', " \
                   "team='{self.team}') " \
                .format(self=self)
