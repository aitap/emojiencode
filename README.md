What is this?
=============

Another way to encode arbitrary bytes into emoji and back, inspired by [base-emoji](https://github.com/pfrazee/base-emoji) and [base64-emoji](https://github.com/watson/base64-emoji). Previous work on this topic uses an alphabet of fixed, round (in base-2) number of emojis. This work attempts to use an arbitrary set of Unicode characters (e.g. all 1311 code points having `Emoji` property or 1093 code points with `Emoji_Presentation` set), without hard-coding the alphabet or making assumptions about its size.

How does it work?
=================

Input stream is considered to be a giant base-`n` big-endian number with each byte or emoji character representing a digit in base `n`, which is then converted to base-`k`. This approach is problematic, because:

 * target representation of the base-`k` number has to be stored in memory
 * the whole algorithm as implemented seems to be `O(N²)`, since the target representation is multiplied (in `O(N)`) by source number base once per each input digit (which there is `O(N)` of).

TODO: perhaps it could be made slightly faster by restarting the output after a small number of bytes (256?)

What does it look like?
=======================

Here is a self-contained emoji-encoding script (produced by concatenating `Numbase.pm` and `transform.pl`), encoded using all Unicode characters posessing `Emoji` property:

3➿🎥🦧🎟🎡✌💭💞😿🦉🀄🛶🔭💥🔪👕🦨🔼🤬🥃📿⛱🦠🎆🔨➖⏩♉🧄💦⚾🍷🦏🍏🏆🐍⛷😺✅🔲🐢💆🕴📼🕌📊📤🎉🌪🏟🧄⬅🐨♌🪕🤱⛄🎉🌈🩰↗🎣🇧🦗🤧⛄🐲↪🙍🔉🚣🟠🇵😅☮😇😳😠👲🥯📴❕⛺🤵🎥🇦🥧🚾🕘🧫🟤📰🔔💐💭0🏞🏆🐒🛕⏯💽🐆🕊😨🚡🦼🇮💩💂🟧🦳🥼🌞🌒🇫⛰🀄🏘🛕☀🐮🤼🔭🌿❔🚦🇾➗🐍◾🐶🪔🤥🐕🚩🈚🤕🩸🔎⛩⏲🕠🗺✌🚠😖🤒🐶🍸👁🍄🥂🐶🚅🚬✊🎥⛱🦅⛷⏭🧶🐓♻📺🙄📚🙍🥍🐰🎿📄🌚🏣💘🏽🕳💤🔈🕦🏕🦐💄😅🔛🎣🆒🥉🐆🧇🤰🩺😕👄🖱🐂🐚🧀🚗⚱🗃⛪💼👈🥖☑👨🎱👏🚰👰9🏇🎻🏔🐚🎠♎🛺📯🤎▶🥎💵🔤🌵🌮💽©🥥📔🇻🦪🟨🧓🏘🌹👳🃏🏜🛥🏃🏇🔵😤😧🐯👛🌷🍼4😍🟢💿🦆🏛🕓🦼😢💚7🌗🦦📷⏮🌛🐶🦑🌛🦠🤪🥵🕞🍩😒🦠🇶♑◼💾🐿😅🧵😧🤳😁⤴➰🍶🧡◻☁🈲9💾🔟🔯🌿🇶⏯🍍🦱🛫🆑🈚🦂🗻🥿🔢😪🕤😻🔀🛄🖖🈸💔💨😎⏹🍑🟪🔵🖊🪐🆚📌🤝🧀🏹🍅⏸🕷🧤🌹📅🖤🏹📔💹🐺🦄♻🔒🩳🇨🔖🉑🧳🔦🧤🏗✈🧑📶🏅💪🔃😏📶📭🧘🐮✌✴🕳😚📿🔮🥱🧭💬🚡🔨♥🍍🌶🔺🤟👘🔻😆🦘🕦🧴💥🤘🎵🕶8⚫🔭🏜🚎😊🔽🚟🕴🥵🎪🧇💟↗🥂💎🍛🏅💡⚛🍺🩲♊💋🦾🦐🦡😠♻❣📪2👑👭🔼🦱💂🥊🏷✍8😇🦶🐲🥗📏🦛📒😤🛩🙀🗄🔜9🌸😚🏍⏰🗼🕸🎸🕦⛰🌕💂🎩✅♒🍵💪⚱🦾🌽🧠🦌🗻🦿🦰🦮🌔🧩👠⛎💫👒🖍🤓🚱🌩🐘💎📝🆒👤🦆🐩💺🖲📅📹🧭🇧♍🌆😼🈴💸🍵🔏✌🆑👣🚸🌲🤿🕸🔹🧕↔♒♾🏦🍓💩🇾❇🛃😍⚫🏓🎗🦡🦡🆙🔉🐮🅰🥅🧖🔖📿➖🏓🤮🕞👳😏🤦😶🎭🧮🥶🅾👣🧇💎⏬💋📁😅🧡😘🥦🥻😾✒🏊🤓😂🍂🤨⚛👖⛄🔡🚑😦🧞🦊😲🔽Ⓜ🟧😍😯🥂8🗃🍣🌽🐤🧪⛅🏘📂🍘📭💄🥇⛎💋😹📸🏅🌒🐾🦁🛄🧆🦊🈷🥝🤞🔟🔲🍎🙅🎉🔞🚅🗾🦋❄🚀😥❓👍🥚🦌😞🛎🈚🎴🤺🦨📶⭐🏬🇧🛢🍑🐬🚁💩🐈🍘🩱🎒📣🔗🛋🙆🪕🕕🛏🍮🦐💵🦓🔦🐛🍏🍢💨💒✒🌤🎗🧰🥟🎴🉐👇😨↔💬🐙🕴🚰⏫🦺🩺🐻🦻👎🥟🕋🤟🗿🏀🕺💰✝🐛☝💇⌛❇🧘♟🌡🖤🍝🐕☮🐙🏻⬛🦕🤸🍧🪁🔺🐒😸🟤📵🐫🧿🏢✂⚓♌🇴☀🇩🎣🧩💥👆🗜🍠👓⛹🌂🔶🦒😮🛬↔🧺#🈁🈺🦇🚼🍽🦚🏧📘🩸🍊🤳🪀🥋💞🛴🦰😗🍩🦯🏷🇩⚫🎿🦻🤿🈚💨🖼🈂🎡☠🥍🤥🇻👳🦎📴❄🛄🥩🥓🏍🛑🛢🐙⚡🕳🪒🌎🛋🏕🈶〽💺🍝💁☢⤵♦🐴↖🏹😦🐯🕙▫🤪🚍🛀🎡🍰😶👔🌹📽♎🇶🚛🧼😗🌕❕🤫🌖🍢💴💍♟🔼🕹⬇🏽📼😃🔪💑🚤🌋💃🐤🍺🍙☎↔📵😶😴🍓🔯🦧🧿🇽🟠▪🖤📼㊗🇽🐜🦪🤎🗻⚔🤼⚒🍱🔂📬🥿🏏🤮☂6🐆🚎👿🆒🥩😻🌞🇯🎌🤽📦⚾😅🐁🙎🐜🥒♌👽🕑📦🍩🍻🥏🔞👵🥃📑🤨😅🦢👱🅾🌥🍧✒🖖🤎📜🍈💟👄🎸🐉🔐🦎🐼🚢🕷🧣⏹🥳🐙↩🥏🍮👻🗞🚐♾🕕🧕😂🤓🦐🌸🐚⬛⛸💬🦽♀🏵🙈🥣🦛🙂😠🧫⚕⚛🌻♒🧒👑🕺👝🛳🥗🚵🌵✨🌥🙍👇🟩🅰🇶🟩🧿🌬🏿🟪🤸🚯😘🎂🎠👱🤒😆🏮🧧🚱🚂👞🔏🚞👑🍢🧧👄🎈🧼↔📡⬇🍥📸💎🚄🔉🗑🚓6🍊🟥🚨🔛🥈🇫🥑🔍🧇💎🐝🦵🧶🏀📴💈♐👷⛺🍶🌙💘〰🌕🏤🥶🎹🕊👎🎐🍑🛄🐩🤡🍐🧴🦑➗👌🚚💻🏈👉🦏🤝↗🏗🌄🍋🇲🚕🥖🦉🔻⏸🕰🤧🧵❇🖤🥙📲📛🙁👰🌮👱🧵🍦🕋📙6🏟✝📩📓🥻🍟👚🇷😵🧁🦮🎲⛱🍚🐴🥂🗣🇽😡✋✨⛄👄⛽🍰🥡🕦🍵🦂😓🎗⏱🍄🍈🔨🦸🥏🚹♏❓🧒🍽💸🧩📏🐆🩲🕢🦈👶🦪🦁➖🦁🔜*🦜🦂🦩🍧🐪⏩♀🛠🧠🦮🦔🏼🌀🍘📓🌳🔤🥚😻🤙🤔🥤🤠◀🌸🐡👻🚖🌩🥢👋🇩🤓⏯🛍🥞🧟♊🖇🔔🈺📥🪐🥖🤑🐕📡🗼🔼🧃🥂🧹💋🪑👳🔚♍🌬🤿📫👎⚛🎾🀄🃏➰🆑👠⛺🎮🇵🎩🦶😽☘👂🚶🌁😜🌂🐮🤼🎬✈📽🌃📧🥀🧔🗽◀🧑📅🐿🍟🥭🧗🗳🎯🈴🙍💠🔄🦰✋🕡🎶🔗🎳🤛🌉🚣🔩🔷🤾📯🦃✍🚒🧳🔤❄🐆📳📄😪🌄🌛🏣🐤🐷🕌✖🍟🚈🥼🛠2🦈🎽🧃🛠🍳🧍⚫✒🤪📏🚎🕖🐞🖊♏🍀🐚😕🎋🤟3🌾🏦💲↗⌛🥒🖼😹🏷🧤🔇🖖🖖🍵🅱🩲🧱♨☀💖🦲🐲🕠📩🇬🈁🧒🤸🚍💣🈁🌽🖋🤒✝🌎🤍🍑🇵🐢🕦🥜👜🔷⛓🎺👹⏹📐📷↔🟤⚕🌜🌺🚹😻💶🏵💓🚝🍺🗾🗜🎓🔜🌔📅🥚⛴🍍🥛🤧🎄🚣😱☁🍉😗🦪🌖🐱🇦☃🦆🍬🔖💣⬅🚚🔳1🍰❓🐥🌓🙁🚟👢🌖🙈👠🎰💉1⤴🤷🥁📆💈🍫👕◼📔🏄🌅🇹🏖😶💜🥤🎻🌵⛎🙌🌥🐅🚝🍪🔜🥀💊📏🗯💕🐀🚃🙁🍗♉🙇⛑🧢🗿📦🔩🎑🍓🧒📼🚛🏓🌐🗿‼🔃🪂🤴🥳➕🦂🐅⛹💀🦦📹🚥📛🦇▪🌃🕖💈🔸

In UTF-8, it occupies about three times more space than the original. In unicode code points, it is around 30% less.

But why?
========

Mu.
