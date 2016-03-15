#ifndef TREEMODEL_H
#define TREEMODEL_H

#include "MatrixModel.h"


class TreeModel : public MatrixModel
{
    public:
        TreeModel(wxXmlNode *node, const NetInfoClass &netInfo, bool zeroBased = false);
        virtual ~TreeModel();
    
        virtual int GetNumStrands() const override;
        virtual int OnPropertyGridChange(wxPropertyGridInterface *grid, wxPropertyGridEvent& event) override;

    protected:
        virtual void AddStyleProperties(wxPropertyGridInterface *grid) override;
        virtual void InitModel() override;
    private:
        int treeType;
        long degrees;
        void SetTreeCoord(long degrees);
};

#endif // TREEMODEL_H
