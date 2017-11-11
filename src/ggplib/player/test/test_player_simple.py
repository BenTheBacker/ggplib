from ggplib.player import get
from ggplib.player.gamemaster import GameMaster
from ggplib.propnet.lookup import get_database


_setup_once = False
def setup():
    global _setup_once
    if not _setup_once:
        _setup_once = True

        # pre-initialise database
        get_database()

        from ggplib import interface
        interface.initialise_k273(1)

        import ggplib.util.log
        ggplib.util.log.initialise()


def test_tictactoe_play():
    gm = GameMaster("ticTacToe")

    # add two python players
    gm.add_player(get.get_player("pyrandom"), "xplayer")
    gm.add_player(get.get_player("pylegal"), "oplayer")

    gm.start()
    gm.play_to_end()

    # check scores/depth make some sense
    assert sum(gm.scores.values()) == 100
    assert 5 <= gm.depth <= 9

def test_tictactoe_cpp_play():
    gm = GameMaster("ticTacToe")

    # add two c++ players
    gm.add_player(get.get_player("random"), "xplayer")
    gm.add_player(get.get_player("legal"), "oplayer")

    gm.start()
    gm.play_to_end()

    # check scores/depth make some sense
    assert sum(gm.scores.values()) == 100
    assert 5 <= gm.depth <= 9

def test_tictactoe_take_win():
    gm = GameMaster("ticTacToe")

    # add two c++ players
    gm.add_player(get.get_player("ggtest1"), "xplayer")
    gm.add_player(get.get_player("ggtest1"), "oplayer")

    str_state = '''
    (true (control xplayer))
    (true (cell 2 2 x))
    (true (cell 3 2 o))
    (true (cell 3 3 x))
    (true (cell 2 3 o))
    (true (cell 3 1 b))
    (true (cell 2 1 b))
    (true (cell 1 3 b))
    (true (cell 1 2 b))
    (true (cell 1 1 b)) '''

    gm.start(start_state=gm.convert_to_base_state(str_state))

    # play a single move - should take win
    move = gm.play_single_move()
    assert str(move[0]) == "(mark 1 1)"
    assert str(move[1]) == "noop"

    gm.play_to_end(last_move=move)

    # check scores/depth make some sense
    assert gm.scores['xplayer'] == 100
    assert gm.scores['oplayer'] == 0
    assert gm.depth == 1

def test_hex():
    gm = GameMaster("hex")

    # add two c++ players
    gm.add_player(get.get_player("random"), "red")
    gm.add_player(get.get_player("simplemcts"), "blue")

    gm.start(meta_time=30, move_time=3)
    gm.play_to_end()

    # hopefully simplemcts wins
    assert gm.scores["red"] == 0
    assert gm.scores["blue"] == 100

    # check scores/depth make some sense
    assert sum(gm.scores.values()) == 100
    assert gm.depth >= 10
