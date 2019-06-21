all: e.txt ep.txt

emoji-data.txt:
	wget -N http://www.unicode.org/Public/emoji/latest/emoji-data.txt

e.txt: emoji-data.txt dump.pl
	perl dump.pl Emoji < emoji-data.txt > e.txt

ep.txt: emoji-data.txt dump.pl
	perl dump.pl Emoji_Presentation < emoji-data.txt > ep.txt
