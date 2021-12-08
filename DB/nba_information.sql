CREATE TABLE GeneralInfo
(
    info_index INTEGER NOT NULL PRIMARY KEY,
    Conference VARCHAR (20),
    Division VARCHAR (20),
    TeamName VARCHAR (20),
    Location VARCHAR (40),
    ArenaName VARCHAR (20),
    StadiumCapacity INTEGER,
    JoinedLeague INTEGER,
    Coach VARCHAR (20)
);

INSERT INTO GeneralInfo VALUES(1, 'Eastern','Atlantic', 'Boston Celtics', 'Boston, Massachusetts', 'TD Garden', 18624, 1946, 'Ime Udoka');
INSERT INTO GeneralInfo VALUES(2, 'Eastern','Atlantic', 'Brooklyn Nets', 'New York City, New York', 'Barclays Center', 17732, 1976, 'Steve Nash');
INSERT INTO GeneralInfo VALUES(3, 'Eastern','Atlantic', 'New York Knicks', 'New York City, New York', 'Madison Square Garden', 19812, 1946, 'Tom Thibodeau');
INSERT INTO GeneralInfo VALUES(4, 'Eastern','Atlantic', 'Philadelphia 76ers', 'Philadelphia, Pennsylvania', 'Wells Fargo Center', 21600, 1949, 'Doc Rivers');
INSERT INTO GeneralInfo VALUES(5, 'Eastern','Atlantic', 'Toronto Raptors', 'Toronto, Ontario', 'Scotiabank Arena', 19800, 1995, 'Nick Nurse');
INSERT INTO GeneralInfo VALUES(6, 'Eastern','Central', 'Chicago Bulls', 'Chicago, Illinois', 'United Center', 20917, 1966, 'Billy Donovan');
INSERT INTO GeneralInfo VALUES(7, 'Eastern','Central', 'Cleveland Cavaliers', 'Cleveland, Ohio', 'Quicken Loans Arena', 20562, 1970, 'Larry Drew');
INSERT INTO GeneralInfo VALUES(8, 'Eastern','Central', 'Detroit Pistons', 'Detroit, Michigan', 'Little Caesars Arena', 20491, 1948, 'Dwane Casey');
INSERT INTO GeneralInfo VALUES(9, 'Eastern','Central', 'Indiana Pacers', 'Indianapolis, Indiana', 'Bankers Life Fieldhouse', 17923, 1976, 'Rick Carlisle');
INSERT INTO GeneralInfo VALUES(10, 'Eastern','Central', 'Milwaukee Bucks', 'Milwaukee, Wisconsin', 'Fiserv Forum', 18717, 1968, 'Mike Budenholzer');
INSERT INTO GeneralInfo VALUES(11, 'Eastern','Southeast', 'Atlanta Hawks', 'Atlanta, Georgia', 'State Farm Arena', 15711, 1949, 'Nate McMillan');
INSERT INTO GeneralInfo VALUES(12, 'Eastern','Southeast', 'Charlotte Hornets', 'Charlotte, North Carolina', 'Spectrum Center', 19077, 1988, 'James Borrego');
INSERT INTO GeneralInfo VALUES(13, 'Eastern','Southeast', 'Miami Heat', 'Miami, Florida', 'American Airlines Arena', 19600, 1988, 'Erik Spoelstra');
INSERT INTO GeneralInfo VALUES(14, 'Eastern','Southeast', 'Orlando Magic', 'Orlando, Florida', 'Amway Center', 18846, 1989, 'Jamahl Mosley');
INSERT INTO GeneralInfo VALUES(15, 'Eastern','Southeast', 'Washington Wizards', 'Washington, D.C.', 'Capital One Arena', 20356, 1961, 'Wes Unseld Jr.');
INSERT INTO GeneralInfo VALUES(16, 'Western','Northwest', 'Denver Nuggets', 'Denver, Colorado', 'Pepsi Center', 19520, 1976, 'Michael Malone');
INSERT INTO GeneralInfo VALUES(17, 'Western','Northwest', 'Minnesota Timberwolves', 'Minneapolis, Minnesota', 'Target Center', 19356, 1989, 'Chris Finch');
INSERT INTO GeneralInfo VALUES(18, 'Western','Northwest', 'Oklahoma City Thunder', 'Oklahoma City, Oklahoma', 'Chesapeake Energy Arena', 18203, 1967, 'Billy Donovan');
INSERT INTO GeneralInfo VALUES(19, 'Western','Northwest', 'Portland Trail Blazers', 'Portland, Oregon', 'Moda Center', 19441, 1970, 'Chauncey Billups');
INSERT INTO GeneralInfo VALUES(20, 'Western','Northwest', 'Utah Jazz', 'Salt Lake City, Utah', 'Vivint Smart Home Arena', 19911, 1974, 'Quin Snyder');
INSERT INTO GeneralInfo VALUES(21, 'Western','Pacific', 'Golden State Warriors', 'Oakland, California', 'Oracle Arena', 19596, 1946, 'Steve Kerr');
INSERT INTO GeneralInfo VALUES(22, 'Western','Pacific', 'Los Angeles Clippers', 'Los Angeles, California', 'Staples Center', 19060, 1970, 'Tyronn Lue');
INSERT INTO GeneralInfo VALUES(23, 'Western','Pacific', 'Los Angeles Lakers', 'Los Angeles, California', 'Staples Center', 18997, 1948, 'Frank Vogel');
INSERT INTO GeneralInfo VALUES(24, 'Western','Pacific', 'Phoenix Suns', 'Phoenix, Arizona', 'Talking Stick Resort Arena', 18055, 1968, 'Monte Williams');
INSERT INTO GeneralInfo VALUES(25, 'Western','Pacific', 'Sacramento Kings', 'Sacramento, California', 'Golden 1 Center', 17500, 1948, 'Luke Walton');
INSERT INTO GeneralInfo VALUES(26, 'Western','Southwest', 'Dallas Mavericks', 'Dallas, Texas', 'American Airlines Center', 19200, 1980, 'Jason Kidd');
INSERT INTO GeneralInfo VALUES(27, 'Western','Southwest', 'Houston Rockets', 'Houston, Texas', 'Toyota Center', 18055, 1967, 'Stephen Silas');
INSERT INTO GeneralInfo VALUES(28, 'Western','Southwest', 'Memphis Grizzlies', 'Memphis, Tennessee', 'FedExForum', 18119, 1995, 'Taylor Jennings');
INSERT INTO GeneralInfo VALUES(29, 'Western','Southwest', 'New Orleans Pelicans', 'New Orleans, Louisiana', 'Smoothie King Center', 16867, 2002, 'Willie Green');
INSERT INTO GeneralInfo VALUES(30, 'Western','Southwest', 'San Antonio Spurs', 'San Antonio, Texas', 'AT&T Center', 18418, 1976, 'Gregg Popovich');

CREATE TABLE Distances (
    BeginningTeamName VARCHAR(20),
    BeginningArena VARCHAR(20),
    EndingTeamName VARCHAR(20),
    Distance FLOAT
);


INSERT INTO Distances Values('Atlanta Hawks', 'State Farm Arena', 'Charlotte Hornets', 244.8);
INSERT INTO Distances Values('Atlanta Hawks', 'State Farm Arena', 'Memphis Grizzlies', 383.8);
INSERT INTO Distances Values('Atlanta Hawks', 'State Farm Arena', 'New Orleans Pelicans', 469.1);
INSERT INTO Distances Values('Atlanta Hawks', 'State Farm Arena', 'Orlando Magic', 438.8);
INSERT INTO Distances Values('Boston Celtics', 'TD Garden', 'New York Knicks', 215.3);
INSERT INTO Distances Values('Boston Celtics', 'TD Garden', 'Toronto Raptors', 550.0);
INSERT INTO Distances Values('Brooklyn Nets', 'Barclays Center', 'New York Knicks', 5.1);
INSERT INTO Distances Values('Brooklyn Nets', 'Barclays Center', 'Philadelphia 76ers', 97.4);
INSERT INTO Distances Values('Charlotte Hornets', 'Spectrum Center', 'Atlanta Hawks', 244.8);
INSERT INTO Distances Values('Charlotte Hornets', 'Spectrum Center', 'Indiana Pacers', 585.1);
INSERT INTO Distances Values('Charlotte Hornets', 'Spectrum Center', 'Miami Heat', 730.9);
INSERT INTO Distances Values('Charlotte Hornets', 'Spectrum Center', 'Washington Wizards', 402.0);
INSERT INTO Distances Values('Chicago Bulls', 'United Center', 'Detroit Pistons', 282.6);
INSERT INTO Distances Values('Chicago Bulls', 'United Center', 'Indiana Pacers', 181.6);
INSERT INTO Distances Values('Chicago Bulls', 'United Center', 'Milwaukee Bucks', 92.1);
INSERT INTO Distances Values('Cleveland Cavaliers', 'Quicken Loans Arena', 'Detroit Pistons', 164.9);
INSERT INTO Distances Values('Cleveland Cavaliers', 'Quicken Loans Arena', 'Indiana Pacers', 315.5);
INSERT INTO Distances Values('Cleveland Cavaliers', 'Quicken Loans Arena', 'Philadelphia 76ers', 431.2);
INSERT INTO Distances Values('Cleveland Cavaliers', 'Quicken Loans Arena', 'Washington Wizards', 371.0);
INSERT INTO Distances Values('Dallas Mavericks', 'American Airlines Center', 'Houston Rockets', 239.8);
INSERT INTO Distances Values('Dallas Mavericks', 'American Airlines Center', 'Oklahoma City Thunder', 206.7);
INSERT INTO Distances Values('Dallas Mavericks', 'American Airlines Center', 'San Antonio Spurs', 273.8);
INSERT INTO Distances Values('Denver Nuggets', 'Pepsi Center', 'Los Angeles Lakers', 1016.1);
INSERT INTO Distances Values('Denver Nuggets', 'Pepsi Center', 'Minnesota Timberwolves', 913.9);
INSERT INTO Distances Values('Denver Nuggets', 'Pepsi Center', 'Oklahoma City Thunder', 679.6);
INSERT INTO Distances Values('Denver Nuggets', 'Pepsi Center', 'Phoenix Suns', 862.4);
INSERT INTO Distances Values('Denver Nuggets', 'Pepsi Center', 'Utah Jazz', 519.1);
INSERT INTO Distances Values('Detroit Pistons', 'Little Caesars Arena', 'Chicago Bulls', 282.6);
INSERT INTO Distances Values('Detroit Pistons', 'Little Caesars Arena', 'Cleveland Cavaliers', 164.9);
INSERT INTO Distances Values('Detroit Pistons', 'Little Caesars Arena', 'Minnesota Timberwolves', 694.7);
INSERT INTO Distances Values('Detroit Pistons', 'Little Caesars Arena', 'New York Knicks', 616.1);
INSERT INTO Distances Values('Detroit Pistons', 'Little Caesars Arena', 'Toronto Raptors', 231.0);
INSERT INTO Distances Values('Golden State Warriors', 'Oracle Arena', 'Los Angeles Lakers', 385.1);
INSERT INTO Distances Values('Golden State Warriors', 'Oracle Arena', 'Sacramento Kings', 87.9);
INSERT INTO Distances Values('Houston Rockets', 'Toyota Center', 'Dallas Mavericks', 239.8);
INSERT INTO Distances Values('Houston Rockets', 'Toyota Center', 'New Orleans Pelicans', 347.7);
INSERT INTO Distances Values('Houston Rockets', 'Toyota Center', 'San Antonio Spurs', 197.4);
INSERT INTO Distances Values('Indiana Pacers', 'Bankers Life Fieldhouse', 'Charlotte Hornets', 585.1);
INSERT INTO Distances Values('Indiana Pacers', 'Bankers Life Fieldhouse', 'Chicago Bulls', 181.6);
INSERT INTO Distances Values('Indiana Pacers', 'Bankers Life Fieldhouse', 'Cleveland Cavaliers', 315.5);
INSERT INTO Distances Values('Los Angeles Clippers', 'Staples Center', 'Los Angeles Lakers', 0.0);
INSERT INTO Distances Values('Los Angeles Clippers', 'Staples Center', 'Denver Nuggets', 1016.1);
INSERT INTO Distances Values('Los Angeles Clippers', 'Staples Center', 'Golden State Warriors', 385.1);
INSERT INTO Distances Values('Los Angeles Clippers', 'Staples Center', 'Phoenix Suns', 373.0);
INSERT INTO Distances Values('Los Angeles Clippers', 'Staples Center', 'Sacramento Kings', 388.4);
INSERT INTO Distances Values('Los Angeles Clippers', 'Staples Center', 'Utah Jazz', 688.4);
INSERT INTO Distances Values('Los Angeles Lakers', 'Staples Center', 'Los Angeles Clippers', 0.0);
INSERT INTO Distances Values('Los Angeles Lakers', 'Staples Center', 'Denver Nuggets', 1016.1);
INSERT INTO Distances Values('Los Angeles Lakers', 'Staples Center', 'Golden State Warriors', 385.1);
INSERT INTO Distances Values('Los Angeles Lakers', 'Staples Center', 'Phoenix Suns', 373.0);
INSERT INTO Distances Values('Los Angeles Lakers', 'Staples Center', 'Sacramento Kings', 388.4);
INSERT INTO Distances Values('Los Angeles Lakers', 'Staples Center', 'Utah Jazz', 688.4);
INSERT INTO Distances Values('Memphis Grizzlies', 'FedExForum', 'Atlanta Hawks', 383.8);
INSERT INTO Distances Values('Memphis Grizzlies', 'FedExForum', 'New Orleans Pelicans', 395.0);
INSERT INTO Distances Values('Memphis Grizzlies', 'FedExForum', 'Oklahoma City Thunder', 466.0);
INSERT INTO Distances Values('Miami Heat', 'American Airlines Arena', 'Charlotte Hornets', 730.9);
INSERT INTO Distances Values('Miami Heat', 'American Airlines Arena', 'New Orleans Pelicans', 866.1);
INSERT INTO Distances Values('Miami Heat', 'American Airlines Arena', 'Orlando Magic', 235.6);
INSERT INTO Distances Values('Milwaukee Bucks', 'Fiserv Forum', 'Chicago Bulls', 92.1);
INSERT INTO Distances Values('Milwaukee Bucks', 'Fiserv Forum', 'Minnesota Timberwolves', 337.1);
INSERT INTO Distances Values('Minnesota Timberwolves', 'Target Center', 'Denver Nuggets', 913.9);
INSERT INTO Distances Values('Minnesota Timberwolves', 'Target Center', 'Detroit Pistons', 694.7);
INSERT INTO Distances Values('Minnesota Timberwolves', 'Target Center', 'Milwaukee Bucks', 337.1);
INSERT INTO Distances Values('Minnesota Timberwolves', 'Target Center', 'Portland Trail Blazers', 1729.3);
INSERT INTO Distances Values('New Orleans Pelicans', 'Smoothie King Center', 'Atlanta Hawks', 469.1);
INSERT INTO Distances Values('New Orleans Pelicans', 'Smoothie King Center', 'Houston Rockets', 347.7);
INSERT INTO Distances Values('New Orleans Pelicans', 'Smoothie King Center', 'Memphis Grizzlies', 395.0);
INSERT INTO Distances Values('New Orleans Pelicans', 'Smoothie King Center', 'Miami Heat', 866.1);
INSERT INTO Distances Values('New York Knicks', 'Madison Square Garden', 'Boston Celtics', 215.3);
INSERT INTO Distances Values('New York Knicks', 'Madison Square Garden', 'Brooklyn Nets', 5.1);
INSERT INTO Distances Values('New York Knicks', 'Madison Square Garden', 'Detroit Pistons', 616.1);
INSERT INTO Distances Values('New York Knicks', 'Madison Square Garden', 'Toronto Raptors', 491.1);
INSERT INTO Distances Values('Oklahoma City Thunder', 'Chesapeake Energy Arena', 'Dallas Mavericks', 206.7);
INSERT INTO Distances Values('Oklahoma City Thunder', 'Chesapeake Energy Arena', 'Denver Nuggets', 679.6);
INSERT INTO Distances Values('Oklahoma City Thunder', 'Chesapeake Energy Arena', 'Memphis Grizzlies', 466.0);
INSERT INTO Distances Values('Orlando Magic', 'Amway Center', 'Atlanta Hawks', 438.8);
INSERT INTO Distances Values('Orlando Magic', 'Amway Center', 'Miami Heat', 235.6);
INSERT INTO Distances Values('Philadelphia 76ers', 'Wells Fargo Center', 'Brooklyn Nets', 97.4);
INSERT INTO Distances Values('Philadelphia 76ers', 'Wells Fargo Center', 'Cleveland Cavaliers', 431.2);
INSERT INTO Distances Values('Philadelphia 76ers', 'Wells Fargo Center', 'Washington Wizards', 140.0);
INSERT INTO Distances Values('Phoenix Suns', 'Talking Stick Resort Arena', 'Denver Nuggets', 862.4);
INSERT INTO Distances Values('Phoenix Suns', 'Talking Stick Resort Arena', 'Los Angeles Lakers', 373.0);
INSERT INTO Distances Values('Portland Trail Blazers', 'Moda Center', 'Minnesota Timberwolves', 1729.3);
INSERT INTO Distances Values('Portland Trail Blazers', 'Moda Center', 'Sacramento Kings', 579.7);
INSERT INTO Distances Values('Portland Trail Blazers', 'Moda Center', 'Utah Jazz', 765.5);
INSERT INTO Distances Values('Sacramento Kings', 'Golden 1 Center', 'Golden State Warriors', 87.9);
INSERT INTO Distances Values('Sacramento Kings', 'Golden 1 Center', 'Los Angeles Lakers', 388.4);
INSERT INTO Distances Values('Sacramento Kings', 'Golden 1 Center', 'Portland Trail Blazers', 579.7);
INSERT INTO Distances Values('San Antonio Spurs', 'AT&T Center', 'Dallas Mavericks', 273.8);
INSERT INTO Distances Values('San Antonio Spurs', 'AT&T Center', 'Houston Rockets', 197.4);
INSERT INTO Distances Values('Toronto Raptors', 'Scotiabank Arena', 'Boston Celtics', 550.0);
INSERT INTO Distances Values('Toronto Raptors', 'Scotiabank Arena', 'Detroit Pistons', 231.0);
INSERT INTO Distances Values('Toronto Raptors', 'Scotiabank Arena', 'New York Knicks', 491.1);
INSERT INTO Distances Values('Utah Jazz', 'Vivint Smart Home Arena', 'Denver Nuggets', 519.1);
INSERT INTO Distances Values('Utah Jazz', 'Vivint Smart Home Arena', 'Los Angeles Lakers', 688.4);
INSERT INTO Distances Values('Utah Jazz', 'Vivint Smart Home Arena', 'Portland Trail Blazers', 765.5);
INSERT INTO Distances Values('Washington Wizards', 'Capital One Arena', 'Charlotte Hornets', 402.0);
INSERT INTO Distances Values('Washington Wizards', 'Capital One Arena', 'Cleveland Cavaliers', 371.0);
INSERT INTO Distances Values('Washington Wizards', 'Capital One Arena', 'Philadelphia 76ers', 140.0);

CREATE TABLE Souvenirs (
    TeamName VARCHAR(20),
    SouvenirName VARCHAR(20),
    Price FLOAT
);

INSERT INTO Souvenirs VALUES ('Boston Celtics', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Boston Celtics', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Boston Celtics', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Boston Celtics', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Brooklyn Nets', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Brooklyn Nets', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Brooklyn Nets', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Brooklyn Nets', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('New York Knicks', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('New York Knicks', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('New York Knicks', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('New York Knicks', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Philadelphia 76ers', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Philadelphia 76ers', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Philadelphia 76ers', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Philadelphia 76ers', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Toronto Raptors', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Toronto Raptors', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Toronto Raptors', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Toronto Raptors', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Chicago Bulls', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Chicago Bulls', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Chicago Bulls', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Chicago Bulls', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Cleveland Cavaliers', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Cleveland Cavaliers', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Cleveland Cavaliers', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Cleveland Cavaliers', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Detroit Pistons', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Detroit Pistons', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Detroit Pistons', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Detroit Pistons', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Indiana Pacers', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Indiana Pacers', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Indiana Pacers', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Indiana Pacers', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Milwaukee Bucks', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Milwaukee Bucks', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Milwaukee Bucks', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Milwaukee Bucks', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Atlanta Hawks', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Atlanta Hawks', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Atlanta Hawks', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Atlanta Hawks', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Charlotte Hornets', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Charlotte Hornets', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Charlotte Hornets', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Charlotte Hornets', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Washington Wizards', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Washington Wizards', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Washington Wizards', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Washington Wizards', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Denver Nuggets', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Denver Nuggets', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Denver Nuggets', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Denver Nuggets', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Minnesota Timberwolves', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Minnesota Timberwolves', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Minnesota Timberwolves', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Minnesota Timberwolves', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Oklahoma City Thunder ', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Oklahoma City Thunder ', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Oklahoma City Thunder ', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Oklahoma City Thunder ', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Portland Trail Blazers', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Portland Trail Blazers', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Portland Trail Blazers', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Portland Trail Blazers', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Utah Jazz', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Utah Jazz', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Utah Jazz', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Utah Jazz', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Golden State Warriors', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Golden State Warriors', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Golden State Warriors', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Golden State Warriors', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Los Angeles Clippers', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Los Angeles Clippers', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Los Angeles Clippers', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Los Angeles Clippers', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Los Angeles Lakers', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Los Angeles Lakers', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Los Angeles Lakers', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Los Angeles Lakers', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Phoenix Suns', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Phoenix Suns', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Phoenix Suns', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Phoenix Suns', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Sacramento Kings', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Sacramento Kings', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Sacramento Kings', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Sacramento Kings', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Dallas Mavericks', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Dallas Mavericks', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Dallas Mavericks', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Dallas Mavericks', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Houston Rockets', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Houston Rockets', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Houston Rockets', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Houston Rockets', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Memphis Grizzlies', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Memphis Grizzlies', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Memphis Grizzlies', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Memphis Grizzlies', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('New Orleans Pelicans', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('New Orleans Pelicans', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('New Orleans Pelicans', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('New Orleans Pelicans', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('San Antonio Spurs', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('San Antonio Spurs', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('San Antonio Spurs', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('San Antonio Spurs', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Miami Heat', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Miami Heat', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Miami Heat', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Miami Heat', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Orlando Magic', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Orlando Magic', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Orlando Magic', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Orlando Magic', 'Team jersey', 179.79);
INSERT INTO Souvenirs VALUES ('Oklahoma City Thunder', 'Autographed Basketball', 49.99);
INSERT INTO Souvenirs VALUES ('Oklahoma City Thunder', 'Team pennant', 17.99);
INSERT INTO Souvenirs VALUES ('Oklahoma City Thunder', 'Team picture', 29.89);
INSERT INTO Souvenirs VALUES ('Oklahoma City Thunder', 'Team jersey', 179.79);




