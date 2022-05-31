BBall Description

Program reads two text files, one containing a list of currently existing MLB teams and the other containing a list of all teams that ever won the World Series.

View commands
- Modern Teams - lists all modern BB teams
- Series Winners - lists all Series winners
- Never Won Series - lists all current teams that never won a series

File commands
- New - clears old lists and reads in the files again

Modern Teams command
- lists all modern teams, as stored in a CStringArray, arTeams
- writes the teams out in city team format, one team per line

Series Winners command
- lists all World Series winners since 1903 (no series in 1904 or 1994), as stored in a CStringArray, arWinners
- writes the winners out in city team year format, one team per line

Never Won Series command
- lists all current teams that never won a series
- copies arTeams into arNoWins
- compares each item in arTeams with arWinners - deletes each team that has at least one win from arNoWins
- writes the non-winners out in city team format, one team per line

OnFileNew override
- reads in the two files

DeleteContents override
- deletes all items in all three lists