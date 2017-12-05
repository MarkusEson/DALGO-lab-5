#ifndef TREEVIEWWIDGET_H
#define TREEVIEWWIDGET_H

#include <QWidget>
#include "node.h"
#include <QRect>
#include <map>
#include <set>
#include <assert.h>

#include <stdio.h>


class TreeViewWidget : public QWidget
{
    Q_OBJECT
    static TreeViewWidget *_sTheOne;

    Node                     *_pRoot = nullptr;
    Node                     *_pNodeUnderMouse = nullptr;
    Node                     *_nodeFlashed = nullptr;
    Node                     *_nodeThatIsTarget = nullptr;

    int                       _durationOfDelay = 200;

    std::map<Node*, QPointF>  _locationFromNodeptr;
    std::set<Node*>           _nodesExisting;
    std::set<Node*>           _nodesThatAreRed;


    Node *subtreeFromRandom(int depth);
    void  destroySubtree(Node *pRoot);

    void paintNode(QPainter &painter, QPoint pt, int width, QColor color);
    int nextkeyWhenDoAssignKeyvalues(Node *pSubtree, int firstValue);
    int size(Node *pRoot);
    QColor colorFromKey(int key);
    void drawArcs(QPainter &painter, QPointF locationOfParent, Node *pSubtree);
    void drawArc(QPainter &painter, QPointF ptf1, QPointF ptf2);
    void fillNode(QPainter &painter, Node *pNode);
    void drawBorderOfNode(QPainter &painter, Node *pNode);

    QPoint ptFromLocation(QPointF ptf);
    void fillNodesInSubtree(QPainter &painter, Node *pNode);
    float distance(QPoint pt1, QPoint pt2);
    QRect rectFromNode(Node *pNode);
    Node *nodeFromPos(QPoint pt);
    int hOfTree(Node *pRoot);
    void setDesiredLocations(Node *pRoot, std::map<Node *, QPointF> &locationFromNode);
    void setDesiredLocations(Node *pRoot, int depth, int &x, float dx, float dy, std::map<Node *, QPointF> &locationFromNode);
    void drawBorders(QPainter &painter);
    void addParentlocationToNewnodes(Node *pRoot, QPointF locationOfParent, std::map<Node *, QPointF> &locations);
    void animateTheChange();
    int sumOfDepth(Node *pRoot, int depthOfThisNode);
    int antalNoder(Node *pRoot);
public:
    static TreeViewWidget *theOne() { return _sTheOne; }
    Node* root() { return _pRoot; }
    bool readTree(FILE* fp);
    bool saveTree(FILE* fp);


    void setDurationOfDelay(int duration) { _durationOfDelay = duration; }
    void nodeAdded( Node *pNode); //  { assert(pNode); _nodesExisting.insert(pNode); }
    void nodeDeleted(Node *pNode);
    void makeRed(Node* pNode);
    void flashNode(Node* pNode);
    bool isTarget(Node* pNode);


    void insertKeyToSearchtree(int key);
    void removeKeyFromSearchtree(int key);
    explicit TreeViewWidget(QWidget *parent = nullptr);

    void updateVisualTree();

    void createRandomTree();
    void createRandomSearchTree(int size);
    void paintEvent(QPaintEvent*event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void insertMultipleRandomKeysToSearchtree(int numberOfKeysToInsert);
    void removeMultipleRandomKeysFromSearchtree(int numberOfKeysToRemove);
    void insertRemoveRandomkeys(int nbrIterations);
    void visualWait(int milliseconds);
signals:

private slots:
    void showContextMenu(const QPoint& point);

};

#endif // TREEVIEWWIDGET_H
