#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    renderArea = ui->renderArea;
    astar = renderArea->astar;
    simulated = false;
}

/**
 * @brief Start the simulator.
 */
void MainWindow::on_startButton_clicked()
{

    if (simulated) {
        ui->statusBox->setText(tr("Please reset!"));
        renderArea->update();
        return;
    }
    //simulated = true;
    ui->statusBox->setText(tr("Started"));
    renderArea->update();
    astar->setStepSize(ui->stepSize->text().toInt());

    assert(astar->step_size > 0);
  

   
    astar->initialize();
    int f = 0;
    while(!astar->reached)
    {

        
        astar->get_neighbour(astar->open[astar->open.size() - 1]);
        astar->closed.push_back(astar->open[astar->open.size() - 1]);
        node *j = astar->open[astar->open.size() - 1];
        astar->open.pop_back();
        
        int q = astar->neighbour.size();
        for (int i = 0; i < q; ++i)
        {
            
            float x = astar->neighbour[i]->position.x();
            float y = astar->neighbour[i]->position.y();
            
            if((x > WORLD_WIDTH) || (y > WORLD_HEIGHT) || (x < 0) || (y < 0))
            {   
                astar->neighbour.erase(astar->neighbour.begin() + i);
                i--;
                q--;
                continue;
            }
            if(astar->distance(astar->neighbour[i]->position , astar->currentPos) < FIELD_OF_VIEW)
            {
                if(astar->obstacles->isSegmentInObstacle(astar->neighbour[i]->position, astar->neighbour[i]->parent->position))
                {
                    
                    astar->neighbour.erase(astar->neighbour.begin() + i);
                    i--;
                    q--;
                }
            }

        }
       
        astar->show_neighbour();
        astar->explore();
     
        if(f == 0)
        {
            astar->open.pop_back();
            f =1;
        }
        renderArea->update();
        
    }
    
    astar->get_path();
   
    renderArea->update();
}

void MainWindow::on_moveButton_clicked()
{
    astar->currentPos = astar->path[astar->path.size() - 10]->position;
    astar->reached = false;
    astar->old_path = astar->path;
    if(astar->currentPos.x() == END_POS_X && astar->currentPos.y() == END_POS_Y)
    {
        simulated = true;;
    }
    astar->open.clear();
    astar->open.resize(0);
    astar->neighbour.clear();
    astar->neighbour.resize(0);
    astar->closed.clear();
    astar->closed.resize(0);
    astar->path.clear();
    astar->path.resize(0);
    
    
    this->on_startButton_clicked();
    renderArea->update();
}

/**
 * @brief Delete all obstacles, nodes and paths from the simulator.
 */


void MainWindow::on_resetButton_clicked()
{
    simulated = false;
    ui->statusBox->setText(tr(""));
    astar->obstacles->obstacles.clear();
    astar->obstacles->obstacles.resize(0);
    
    astar->open.clear();
    astar->open.resize(0);
    astar->neighbour.clear();
    astar->neighbour.resize(0);
    astar->closed.clear();
    astar->closed.resize(0);
    astar->path.clear();
    astar->path.resize(0);
    astar->reached = false;
    astar->initialize();
    renderArea->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
