CREATE TABLE GISdata
(
    info_index INTEGER NOT NULL PRIMARY KEY ,
    Conference VARCHAR (20),
    Division VARCHAR (20),
    TeamName VARCHAR (20),
    Location VARCHAR (40),
    ArenaName VARCHAR (20),
    StadiumCapacity INTEGER,
    JoinedLeague INTEGER,
    Coach VARCHAR (20)
);

    INSERT INTO GISdata VALUES(1, 'Eastern','Atlantic', 'Boston Celtics', 'Boston, Massachusetts', 'TD Garden', 18624, 1946, 'Ime Udoka');
    INSERT INTO GISdata VALUES(2, 'Eastern','Atlantic', 'Brooklyn Nets', 'New York City, New York', 'Barclays Center', 17732, 1976, 'Steve Nash');
    INSERT INTO GISdata VALUES(3, 'Eastern','Atlantic', 'New York Knicks', 'New York City, New York', 'Madison Square Garden', 19812, 1946, 'Tom Thibodeau');
    INSERT INTO GISdata VALUES(4, 'Eastern','Atlantic', 'Philadelphia 76ers', 'Philadelphia, Pennsylvania', 'Wells Fargo Center', 21600, 1949, 'Doc Rivers');
    INSERT INTO GISdata VALUES(5, 'Eastern','Atlantic', 'Toronto Raptors', 'Toronto, Ontario', 'Scotiabank Arena', 19800, 1995, 'Nick Nurse');
    INSERT INTO GISdata VALUES(6, 'Eastern','Central', 'Chicago Bulls', 'Chicago, Illinois', 'United Center', 20917, 1966, 'Billy Donovan');
    INSERT INTO GISdata VALUES(7, 'Eastern','Central', 'Cleveland Cavaliers', 'Cleveland, Ohio', 'Quicken Loans Arena', 20562, 1970, 'Larry Drew');
    INSERT INTO GISdata VALUES(8, 'Eastern','Central', 'Detroit Pistons', 'Detroit, Michigan', 'Little Caesars Arena', 20491, 1948, 'Dwane Casey');
    INSERT INTO GISdata VALUES(9, 'Eastern','Central', 'Indiana Pacers', 'Indianapolis, Indiana', 'Bankers Life Fieldhouse', 17923, 1976, 'Rick Carlisle');
    INSERT INTO GISdata VALUES(10, 'Eastern','Central', 'Milwaukee Bucks', 'Milwaukee, Wisconsin', 'Fiserv Forum', 18717, 1968, 'Mike Budenholzer');
    INSERT INTO GISdata VALUES(11, 'Eastern','Southeast', 'Atlanta Hawks', 'Atlanta, Georgia', 'State Farm Arena', 15711, 1949, 'Nate McMillan');
    INSERT INTO GISdata VALUES(12, 'Eastern','Southeast', 'Charlotte Hornets', 'Charlotte, North Carolina', 'Spectrum Center', 19077, 1988, 'James Borrego');
    INSERT INTO GISdata VALUES(13, 'Eastern','Southeast', 'Miami Heat', 'Miami, Florida', 'American Airlines Arena', 19600, 1988, 'Erik Spoelstra');
    INSERT INTO GISdata VALUES(14, 'Eastern','Southeast', 'Orlando Magic', 'Orlando, Florida', 'Amway Center', 18846, 1989, 'Jamahl Mosley');
    INSERT INTO GISdata VALUES(15, 'Eastern','Southeast', 'Washington Wizards', 'Washington, D.C.', 'Capital One Arena', 20356, 1961, 'Wes Unseld Jr.');
    INSERT INTO GISdata VALUES(16, 'Western','Northwest', 'Denver Nuggets', 'Denver, Colorado', 'Pepsi Center', 19520, 1976, 'Michael Malone');
    INSERT INTO GISdata VALUES(17, 'Western','Northwest', 'Minnesota Timberwolves', 'Minneapolis, Minnesota', 'Target Center', 19356, 1989, 'Chris Finch');
    INSERT INTO GISdata VALUES(18, 'Western','Northwest', 'Oklahoma City Thunder', 'Oklahoma City, Oklahoma', 'Chesapeake Energy Arena', 18203, 1967, 'Billy Donovan');
    INSERT INTO GISdata VALUES(19, 'Western','Northwest', 'Portland Trail Blazers', 'Portland, Oregon', 'Moda Center', 19441, 1970, 'Chauncey Billups');
    INSERT INTO GISdata VALUES(20, 'Western','Northwest', 'Utah Jazz', 'Salt Lake City, Utah', 'Vivint Smart Home Arena', 19911, 1974, 'Quin Snyder');
    INSERT INTO GISdata VALUES(21, 'Western','Pacific', 'Golden State Warriors', 'Oakland, California', 'Oracle Arena', 19596, 1946, 'Steve Kerr');
    INSERT INTO GISdata VALUES(22, 'Western','Pacific', 'Los Angeles Clippers', 'Los Angeles, California', 'Staples Center', 19060, 1970, 'Tyronn Lue');
    INSERT INTO GISdata VALUES(23, 'Western','Pacific', 'Los Angeles Lakers', 'Los Angeles, California', 'Staples Center', 18997, 1948, 'Frank Vogel');
    INSERT INTO GISdata VALUES(24, 'Western','Pacific', 'Phoenix Suns', 'Phoenix, Arizona', 'Talking Stick Resort Arena', 18055, 1968, 'Monte Williams');
    INSERT INTO GISdata VALUES(25, 'Western','Pacific', 'Sacramento Kings', 'Sacramento, California', 'Golden 1 Center', 17500, 1948, 'Luke Walton');
    INSERT INTO GISdata VALUES(26, 'Western','Southwest', 'Dallas Mavericks', 'Dallas, Texas', 'American Airlines Center', 19200, 1980, 'Jason Kidd');
    INSERT INTO GISdata VALUES(27, 'Western','Southwest', 'Houston Rockets', 'Houston, Texas', 'Toyota Center', 18055, 1967, 'Stephen Silas');
    INSERT INTO GISdata VALUES(28, 'Western','Southwest', 'Memphis Grizzlies', 'Memphis, Tennessee', 'FedExForum', 18119, 1995, 'Taylor Jennings');
    INSERT INTO GISdata VALUES(29, 'Western','Southwest', 'New Orleans Pelicans', 'New Orleans, Louisiana', 'Smoothie King Center', 16867, 2002, 'Willie Green');
    INSERT INTO GISdata VALUES(30, 'Western','Southwest', 'San Antonio Spurs', 'San Antonio, Texas', 'AT&T Center', 18418, 1976, 'Gregg Popovich');



