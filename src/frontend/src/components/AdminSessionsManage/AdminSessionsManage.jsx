import style from './AdminSessionsManage.module.css'
import { useNavigate } from "react-router-dom"
import { useEffect, useState } from "react"
import axios from 'axios';

const AdminSessionsManage = () => {
  const navigate = useNavigate();
  const [loading, setLoading] = useState(true);
  const [eduCount, setEduCount] = useState(null);
  const [psychoCount, setPsychoCount] = useState(null);
  const [funnyCount,  setFunnyCount] = useState(null);
  const testTypeArray = ["education", "psycho", "funny"]

  useEffect( () => {
    const fetchData = async () => {
      try {
        const response = await axios.get('http://localhost:7500/challenges');
        const dataAPI = response.data
        if ( testTypeArray !== null){
          testTypeArray.map( (testType) => {
            const count = dataAPI.filter(item => item.testType === testType).length;
            switch (testType){
              case 'education':
                setEduCount(count)
                break

              case 'psycho':
                setPsychoCount(count)
                break

              case 'funny':
                setFunnyCount(count)
                break
              default:
            }
            return count
          })
          setLoading(false);
        }
      }
      catch (error) {
        console.error('Error fetching data:', error);
      }
    };
    fetchData();
  }, [testTypeArray])

  if (loading){
    return (
      <div className={style.bodyStyle}></div>
    )
  }

  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>
          <div>
            Настройка
          </div>
          <div>
            тестирования
          </div>
        </div>
        <div className={style.imageBox}>
          <div>
            <img src={`${testTypeArray[0]}.png`} alt={`${testTypeArray[0]}.png`} onClick={ ()=>navigate(`/admin-sessions-view/${testTypeArray[0]}`)}/>
            <div className={style.imageCaption} onClick={ ()=>navigate(`/admin-sessions-view/${testTypeArray[0]}`)}> Education ({eduCount}) </div>
          </div>
          <div>
            <img src={`${testTypeArray[1]}.png`} alt={`${testTypeArray[1]}.png`} onClick={ ()=>navigate(`/admin-sessions-view/${testTypeArray[1]}`)}/>
            <div className={style.imageCaption} onClick={ ()=>navigate(`/admin-sessions-view/${testTypeArray[1]}`)}>Psychological ({psychoCount})</div>
          </div>
          <div>
            <img src={`${testTypeArray[2]}.png`} alt={`${testTypeArray[2]}.png`} onClick={ ()=>navigate(`/admin-sessions-view/${testTypeArray[2]}`)}/>
            <div className={style.imageCaption} onClick={ ()=>navigate(`/admin-sessions-view/${testTypeArray[2]}`)}>Funny ({funnyCount})</div>
          </div>
        </div>
        <div className={style.placeButton}>
          <button className={style.flatButton} onClick={ ()=>navigate(-1)} >Back</button>
        </div>
      </div>
  );
}

export default AdminSessionsManage;
