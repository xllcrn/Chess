#ifndef CHESS_PIECEFACTORY_H
#define CHESS_PIECEFACTORY_H
#include "Piece.h"
#include <Cross.h>
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include <map>
#include <memory>

struct PieceFactory{
    virtual std::shared_ptr<Piece> make(Color) const = 0;
};

struct PawnFactory : PieceFactory{
    std::shared_ptr<Piece> make(Color color) const override;
};

struct QueenFactory : PieceFactory{
    std::shared_ptr<Piece> make(Color color) const override;
};

struct RookFactory : PieceFactory{
    std::shared_ptr<Piece> make(Color color) const override;
};

struct KnightFactory : PieceFactory{
    std::shared_ptr<Piece> make(Color color) const override;
};

struct KingFactory : PieceFactory{
    std::shared_ptr<Piece> make(Color color) const override;
};

struct CrossFactory : PieceFactory{
    std::shared_ptr<Piece> make(Color color) const override;
};

struct BishopFactory : PieceFactory{
    std::shared_ptr<Piece> make(Color color) const override;
};


class BuildPieceFactory
{
    std::map<char, std::shared_ptr<PieceFactory>> piece_factories;
public:
    BuildPieceFactory();
    std::shared_ptr<Piece> make_piece(char const & name);
};

#endif //CHESS_PIECEFACTORY_H