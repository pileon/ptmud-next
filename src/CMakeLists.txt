# TODO: Tests

set(SOURCE_FILES
    act.comm.c         act.social.c    castle.c     fight.c        magic.c    random.c        utils.c
    act.informative.c  act.wizard.c    class.c      graph.c        mail.c     shop.c          weather.c
    act.item.c         alias.c         comm.c       handler.c      mobact.c   spec_assign.c
    act.movement.c     ban.c           config.c     house.c        modify.c   spec_procs.c
    act.offensive.c    boards.c        constants.c  interpreter.c  objsave.c  spell_parser.c
    act.other.c        db.c            limits.c     olc.c          spells.c
    area.c area.h)

add_executable(ptmud-next ${SOURCE_FILES})

add_custom_target(valgrind
        COMMAND valgrind ${CMAKE_CURRENT_BINARY_DIR}/ptmud-next -d${PROJECT_SOURCE_DIR}/lib
        DEPENDS ptmud-next)
