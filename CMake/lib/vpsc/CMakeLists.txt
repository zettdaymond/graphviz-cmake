add_library(${LIB_VPSC}
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/block.cpp
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/block.h
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/blocks.cpp
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/blocks.h
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/constraint.cpp
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/constraint.h
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/csolve_VPSC.cpp
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/csolve_VPSC.h
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/generate-constraints.cpp
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/generate-constraints.h
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/remove_rectangle_overlap.cpp
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/remove_rectangle_overlap.h
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/solve_VPSC.cpp
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/solve_VPSC.h
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/variable.cpp
    ${GRAPHVIZ_SRC_DIR}/lib/vpsc/variable.h
)

